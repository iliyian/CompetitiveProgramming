import json
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['WenQuanYi Zen Hei']
plt.rcParams['font.size'] = 13
plt.rcParams['axes.unicode_minus'] = False

EX = {'icpc_50th_ecfinal', 'ccpc_final'}
pairs = [p for p in json.load(open('pairs_valid.json')) if p['onsite'] not in EX]
sub = [p for p in pairs if p['online_solved'] > 0]
op = np.array([p['online_rank'] / p['online_N_valid'] for p in sub])
sp = np.array([p['onsite_rank'] / p['onsite_N_valid'] for p in sub])

def band(x):
    if x < 0.01: return 0
    if x < 0.10: return 1
    if x < 0.30: return 2
    if x<0.60: return 3
    return 4

yb = np.array([band(x) for x in op]); sz = np.array([band(x) for x in sp])
zf = json.load(open('zone_flow_5band.json')); M = np.array(zf['M']); n = zf['n']
BANDS = ['前1%', '金区', '银区', '铜区', '铁区']
BKEY = ['top1', 'gold', 'silver', 'bronze', 'iron']
COLORS = {'top1': '#e91e8c', 'gold': '#FFD700', 'silver': '#b8b8b8',
          'bronze': '#cd7f32', 'iron': '#7f8c8d'}

ret = M.diagonal() / M.sum(1)
null = M.sum(0) / n
H = []
for b in range(5):
    p = M[b] / M[b].sum(); p = p[p > 0]
    H.append(float(-(p * np.log(p)).sum() / np.log(5)))
marg = M.sum(0) / n
Hnull = float(-(marg * np.log(marg)).sum() / np.log(5))
dev = np.abs(sp - op); sticky = dev <= 0.10
bins = np.linspace(0, 1, 11); bx = []; byy = []
for i in range(10):
    sel = (op >= bins[i]) & (op < bins[i + 1])
    if sel.sum() >= 30:
        bx.append((bins[i] + bins[i + 1]) / 2 * 100); byy.append(sticky[sel].mean() * 100)
widths = [np.percentile(sp[yb == b], 90) - np.percentile(sp[yb == b], 10) for b in range(5)]
print('ret', np.round(ret, 2).tolist(), 'null', np.round(null, 2).tolist())
print('H', [round(h, 2) for h in H], 'Hnull', round(Hnull, 2))
print('sticky', [round(y) for y in byy], 'overall', round(sticky.mean() * 100))
print('widths(pp)', [round(w * 100) for w in widths])

fig, axes = plt.subplots(2, 2, figsize=(15, 10))
ax = axes[0, 0]; x = np.arange(5); w = 0.38
ax.bar(x - w / 2, ret * 100, w, color=[COLORS[k] for k in BKEY], label='实际同档保留率')
ax.bar(x + w / 2, null * 100, w, color='white', edgecolor='k', label='无信息基线')
for i in range(5):
    ax.text(i - w / 2, ret[i] * 100 + 1, f'{ret[i]*100:.0f}%', ha='center', fontsize=11)
ax.set_xticks(x, BANDS, fontsize=12); ax.set_ylim(0, 100)
ax.set_ylabel('正赛落在同档的比例 (%)', fontsize=12)
ax.set_title('① 同档保留率：中间塌陷', fontsize=13)
ax.legend(fontsize=10); ax.grid(alpha=0.25, axis='y')

ax = axes[0, 1]
ax.bar(x, np.array(H) * 100, color=[COLORS[k] for k in BKEY])
ax.axhline(Hnull * 100, color='gray', ls='--', lw=1.3, label=f'无信息基线 {Hnull:.2f}')
for i in range(5):
    ax.text(i, H[i] + 0.015, f'{H[i]:.2f}', ha='center', fontsize=11)
ax.set_xticks(x, BANDS, fontsize=12); ax.set_ylim(0, 1.0)
ax.set_ylabel('归一化条件熵 (0=确定, 1=纯随机)', fontsize=12)
ax.set_title('② 不确定性谱：中间熵最高', fontsize=13)
ax.legend(fontsize=10); ax.grid(alpha=0.25, axis='y')

ax = axes[1, 0]
ax.plot(bx, byy, 'o-', color='#5dade2', lw=2)
ax.axhline(sticky.mean() * 100, color='gray', ls='--', lw=1.2, label=f'全体平均 {sticky.mean()*100:.0f}%')
for xx, yy in zip(bx, byy):
    ax.text(xx, yy + 2.5, f'{yy:.0f}%', ha='center', fontsize=10, color='#2c5f8a')
ax.set_xticks(range(0, 101, 10)); ax.tick_params(labelsize=11); ax.set_ylim(0, 100)
ax.set_xlabel('网络赛百分位 (%)', fontsize=12)
ax.set_ylabel('正赛落在 ±10pp 内的比例 (%)', fontsize=12)
ax.set_title('③ 粘滞窗口：头尾黏、中间滑', fontsize=13)
ax.legend(fontsize=10, loc='upper right'); ax.grid(alpha=0.25)

ax = axes[1, 1]
wpp = np.array(widths) * 100
ax.bar(x, wpp, color=[COLORS[k] for k in BKEY], alpha=0.85)
for i in range(5):
    ax.text(i, wpp[i] + 1, f'{wpp[i]:.0f}pp', ha='center', fontsize=11)
ax.set_xticks(x, BANDS, fontsize=12); ax.set_ylim(0, max(wpp) * 1.2)
ax.set_ylabel('正赛百分位 P10~P90 宽度 (pp)', fontsize=12)
ax.set_title('④ 预测区间宽度：中间最宽', fontsize=13)
ax.grid(alpha=0.25, axis='y')

fig.suptitle('「两头稳、中间摊」的四重证据（11场正式赛, 网络赛0解题对已剔除）', fontsize=16, y=1.00)
fig.tight_layout()
fig.savefig('plots/ushape.png', dpi=115, bbox_inches='tight')
plt.close(fig)
print('saved ushape.png')