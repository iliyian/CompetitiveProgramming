import json
import numpy as np
from scipy.stats import gaussian_kde
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['WenQuanYi Zen Hei']
plt.rcParams['font.size'] = 13
plt.rcParams['axes.unicode_minus'] = False

pairs = [p for p in json.load(open('pairs_valid_no_finals.json')) if p['online_solved'] > 0]
op = np.array([p['online_rank'] / p['online_N_valid'] * 100 for p in pairs])
sp = np.array([p['onsite_rank'] / p['onsite_N_valid'] * 100 for p in pairs])
n = len(pairs)

BANDS = ['金区\n1~10%', '银区\n10~30%', '铜区\n30~60%', '铁区\n>60%']
MEDAL = ['#D4A017', '#9E9E9E', '#B26A2B', '#6E7F80']
CREAM = '#FCFAF5'

def band4(x):
    if x < 10: return 0
    if x < 30: return 1
    if x < 60: return 2
    return 3

zb = np.array([band4(x) for x in op])

# ---------- violin ----------
fig, ax = plt.subplots(figsize=(10.5, 7))
fig.patch.set_facecolor(CREAM); ax.set_facecolor(CREAM)
data = [sp[zb == i] for i in range(4)]
vp = ax.violinplot(data, positions=range(4), widths=0.85, showextrema=False)
for i, body in enumerate(vp['bodies']):
    body.set_facecolor(MEDAL[i]); body.set_alpha(0.5); body.set_edgecolor('none')
for i, d in enumerate(data):
    q1, med, q3 = np.percentile(d, [25, 50, 75])
    ax.vlines(i, q1, q3, color='#3B3226', lw=3)
    ax.scatter(i, med, color=CREAM, s=42, zorder=5, edgecolor='#3B3226', lw=1.6)
    ax.text(i + 0.34, med, f'中位 {med:.0f}%', va='center', fontsize=11, color='#3B3226')
    ax.text(i, -9, f'n={len(d)}', ha='center', fontsize=11, color='#8A7D63')
ax.axhline(10, color='#D4A017', ls=':', lw=1, alpha=0.8)
ax.axhline(30, color='#9E9E9E', ls=':', lw=1, alpha=0.8)
ax.axhline(60, color='#B26A2B', ls=':', lw=1, alpha=0.8)
ax.text(3.62, 10, '金区线', fontsize=9.5, color='#8A7D63', va='center')
ax.text(3.62, 30, '银区线', fontsize=9.5, color='#8A7D63', va='center')
ax.text(3.62, 60, '铜区线', fontsize=9.5, color='#8A7D63', va='center')
ax.set_xticks(range(4), BANDS, fontsize=12)
ax.set_xlim(-0.6, 4.1); ax.set_ylim(-12, 103)
ax.set_ylabel('正赛排名百分位 (%)', fontsize=12)
ax.set_title(f'小提琴：各网络赛档位的正赛百分位分布（每场各算, n={n}）', fontsize=15, pad=14, color='#3B3226')
for s in ['top', 'right']: ax.spines[s].set_visible(False)
ax.grid(alpha=0.18, axis='y')
fig.tight_layout(); fig.savefig('plots/violin_4band.png', dpi=120, bbox_inches='tight', facecolor=CREAM); plt.close(fig)

# ---------- ridgeline ----------
fig, ax = plt.subplots(figsize=(11, 8))
fig.patch.set_facecolor(CREAM); ax.set_facecolor(CREAM)
xs = np.linspace(0, 100, 400)
colors = ['#E9D9AC', '#DFC894', '#D4B57C', '#C9A366', '#BE9150', '#B37E3C', '#A66B2C', '#99591E', '#8C4713', '#7F3512']
offsets = []
for i in range(10):
    sel = (op >= i * 10) & (op < (i + 1) * 10) if i < 9 else (op >= 90)
    d = sp[sel]
    kde = gaussian_kde(d, bw_method=0.28)
    y = kde(xs)
    y = y / y.max() * 0.85
    off = -i * 0.95
    ax.fill_between(xs, off, off + y, facecolor=colors[i], alpha=0.72, lw=1.2, edgecolor='#6E5A3A', zorder=10 - i)
    ax.text(-1.5, off + 0.18, f'{i*10}~{(i+1)*10}%', ha='right', va='bottom', fontsize=11, color='#4A3B22')
    ax.text(101, off + 0.18, f'中位 {np.median(d):.0f}%', ha='left', va='bottom', fontsize=10, color='#8A7D63')
    offsets.append(off)
ax.set_xlim(-16, 118); ax.set_ylim(-9.6, 1.5)
ax.axis('off')
ax.set_title(f'山脊图：网络赛十分位 × 正赛百分位分布（每场各算, n={n}）', fontsize=15, pad=14, color='#3B3226')
ax.text(50, 1.15, '顶部=网络赛最好的队伍；山脊越窄越靠左=预测越集中，越宽越平=越摊', ha='center', fontsize=11, color='#8A7D63')
fig.tight_layout(); fig.savefig('plots/ridgeline.png', dpi=120, bbox_inches='tight', facecolor=CREAM); plt.close(fig)
print('saved violin_4band.png / ridgeline.png')
for i in range(10):
    sel = (op >= i * 10) & (op < (i + 1) * 10) if i < 9 else (op >= 90)
    d = sp[sel]
    print(f'{i*10:3d}~{(i+1)*10:3d}%: n={sel.sum():4d} 中位={np.median(d):5.1f} IQR={np.percentile(d,75)-np.percentile(d,25):5.1f}')