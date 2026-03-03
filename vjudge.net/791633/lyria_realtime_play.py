"""
Gemini Lyria RealTime 实时古典音乐生成 & 播放

使用前:
  pip install google-genai sounddevice numpy
  设置环境变量 GOOGLE_API_KEY=你的API密钥
"""

import asyncio
import numpy as np
import sounddevice as sd
import wave
import os
from google import genai
from google.genai import types

# 音频规格 (Lyria RealTime 固定输出)
SAMPLE_RATE = 48000
CHANNELS = 2
SAMPLE_WIDTH = 2  # 16-bit

# 播放时长(秒), 0 表示无限播放直到 Ctrl+C
DURATION = 60
SAVE_FILE = "classical_output.wav"


async def main():
    api_key = os.environ.get("GOOGLE_API_KEY")
    if not api_key:
        print("错误: 请设置环境变量 GOOGLE_API_KEY")
        print("  PowerShell:  $env:GOOGLE_API_KEY='你的密钥'")
        return

    client = genai.Client(
        api_key=api_key,
        http_options={"api_version": "v1alpha"},
    )

    # 用于实时播放的音频流
    stream = sd.OutputStream(
        samplerate=SAMPLE_RATE,
        channels=CHANNELS,
        dtype="int16",
        blocksize=4800,  # 100ms buffer
    )
    stream.start()

    audio_buffer = bytearray()
    done = asyncio.Event()

    async def receive_and_play(session):
        """接收音频并实时播放"""
        try:
            while not done.is_set():
                async for message in session.receive():
                    chunk = message.server_content.audio_chunks[0].data
                    audio_buffer.extend(chunk)

                    # 转为 numpy 数组并播放
                    samples = np.frombuffer(chunk, dtype=np.int16)
                    samples = samples.reshape(-1, CHANNELS)
                    stream.write(samples)

                    secs = len(audio_buffer) / (SAMPLE_RATE * CHANNELS * SAMPLE_WIDTH)
                    print(f"\r♪ 正在播放古典音乐... {secs:.1f}s", end="", flush=True)

                    if DURATION > 0 and secs >= DURATION:
                        done.set()
                        return
                await asyncio.sleep(1e-3)
        except asyncio.CancelledError:
            pass

    print("🎻 连接 Lyria RealTime...")
    print("🎵 风格: 夜曲 | 钢琴 | 梦幻 | 柔美旋律")
    print(f"⏱  时长: {DURATION}秒 (Ctrl+C 提前停止)\n")

    try:
        async with client.aio.live.music.connect(
            model="models/lyria-realtime-exp"
        ) as session:
            recv_task = asyncio.create_task(receive_and_play(session))

            # 夜曲风格提示词
            await session.set_weighted_prompts(
                prompts=[
                    types.WeightedPrompt(text="Smooth Pianos", weight=2.0),
                    types.WeightedPrompt(text="Dreamy", weight=1.2),
                    types.WeightedPrompt(text="Emotional", weight=1.0),
                    types.WeightedPrompt(text="Subdued Melody", weight=0.8),
                ]
            )

            await session.set_music_generation_config(
                config=types.LiveMusicGenerationConfig(
                    bpm=66,
                    temperature=1.1,
                    brightness=0.35,
                    density=0.3,
                    scale=types.Scale.E_FLAT_MAJOR_C_MINOR,
                    mute_drums=True,
                    mute_bass=True,
                    music_generation_mode=types.MusicGenerationMode.QUALITY,
                )
            )

            await session.play()
            await done.wait()
            await session.stop()
            recv_task.cancel()

    except KeyboardInterrupt:
        print("\n\n⏹  已停止")
    finally:
        stream.stop()
        stream.close()

    # 保存文件
    if audio_buffer:
        print(f"\n💾 保存到 {SAVE_FILE} ...")
        with wave.open(SAVE_FILE, "wb") as wf:
            wf.setnchannels(CHANNELS)
            wf.setsampwidth(SAMPLE_WIDTH)
            wf.setframerate(SAMPLE_RATE)
            wf.writeframes(bytes(audio_buffer))
        mb = os.path.getsize(SAVE_FILE) / (1024 * 1024)
        print(f"✅ 完成! {mb:.1f} MB")


if __name__ == "__main__":
    asyncio.run(main())
