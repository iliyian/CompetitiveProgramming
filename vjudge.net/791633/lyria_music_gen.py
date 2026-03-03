"""
Gemini Lyria RealTime 音乐生成示例
生成一段 Lo-Fi Hip Hop 风格的音乐并保存为 WAV 文件

使用前:
  pip install google-genai
  设置环境变量 GOOGLE_API_KEY=你的API密钥
"""

import asyncio
import wave
import struct
import os
from google import genai
from google.genai import types

# 音频参数 (Lyria RealTime 输出规格)
SAMPLE_RATE = 48000
CHANNELS = 2
SAMPLE_WIDTH = 2  # 16-bit PCM

# 生成时长(秒)
DURATION = 30
OUTPUT_FILE = "output_music.wav"


async def main():
    api_key = os.environ.get("GOOGLE_API_KEY")
    if not api_key:
        print("错误: 请设置环境变量 GOOGLE_API_KEY")
        print("  Windows:  $env:GOOGLE_API_KEY='你的密钥'")
        print("  Linux:    export GOOGLE_API_KEY='你的密钥'")
        return

    client = genai.Client(
        api_key=api_key,
        http_options={"api_version": "v1alpha"},
    )

    audio_buffer = bytearray()
    done = asyncio.Event()

    async def receive_audio(session):
        """接收音频数据块"""
        try:
            while not done.is_set():
                async for message in session.receive():
                    chunk = message.server_content.audio_chunks[0].data
                    audio_buffer.extend(chunk)

                    # 计算已收集的秒数
                    seconds = len(audio_buffer) / (SAMPLE_RATE * CHANNELS * SAMPLE_WIDTH)
                    print(f"\r已生成: {seconds:.1f}s / {DURATION}s", end="", flush=True)

                    if seconds >= DURATION:
                        done.set()
                        return
                await asyncio.sleep(1e-3)
        except asyncio.CancelledError:
            pass

    print(f"正在连接 Lyria RealTime 模型...")
    print(f"风格: Lo-Fi Hip Hop | Chill | Smooth Pianos")
    print(f"时长: {DURATION}秒\n")

    async with client.aio.live.music.connect(
        model="models/lyria-realtime-exp"
    ) as session:
        # 启动接收任务
        recv_task = asyncio.create_task(receive_audio(session))

        # 设置音乐风格提示词
        await session.set_weighted_prompts(
            prompts=[
                types.WeightedPrompt(text="Lo-Fi Hip Hop", weight=1.5),
                types.WeightedPrompt(text="Chill", weight=1.0),
                types.WeightedPrompt(text="Smooth Pianos", weight=1.2),
            ]
        )

        # 设置生成参数
        await session.set_music_generation_config(
            config=types.LiveMusicGenerationConfig(
                bpm=85,
                temperature=1.0,
                brightness=0.4,
                density=0.3,
            )
        )

        # 开始生成
        await session.play()

        # 等待收集足够音频
        await done.wait()

        # 停止生成
        await session.stop()
        recv_task.cancel()

    # 保存为 WAV 文件
    print(f"\n\n正在保存到 {OUTPUT_FILE} ...")
    with wave.open(OUTPUT_FILE, "wb") as wf:
        wf.setnchannels(CHANNELS)
        wf.setsampwidth(SAMPLE_WIDTH)
        wf.setframerate(SAMPLE_RATE)
        wf.writeframes(bytes(audio_buffer))

    file_size = os.path.getsize(OUTPUT_FILE) / (1024 * 1024)
    print(f"完成! 文件大小: {file_size:.1f} MB")


if __name__ == "__main__":
    asyncio.run(main())
