import json
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.colors import LinearSegmentedColormap
plt.rcParams['font.sans-serif'] = ['WenQuanYi Zen Hei']
plt.rcParams['font.size'] = 14
plt.rcParams['axes.unicode_minus'] = False

zf = json.load(open('zone_flow_4band.json'))
M = np.array(zf['M']); n = zf['n']
BANDS = ['金区 1~10%', '银区 10~30%', '铜区 30~60%', '铁区 >60%']
MEDAL = ['#D4A017', '#9E9E9E', '#B26A2B', '#6E7F80']
P = M / M.sum(1, keepdims=True) * 100

# single-hue amber scale (no red-green)
cmap = LinearSegmentedColormap.from_list('amber', ['#FBF8F1', '#F0E3C4', '#DFC27E', '#C9963F', '#8F6119'])

fig, ax = plt.subplots(figsize=(9.8, 7.6))
fig.patch.set_facecolor('#FCFAF5')
ax.set_facecolor('#FCFAF5')
im = ax.imshow(P, cmap=cmap, vmin=0, vmax=100, aspect='auto')

# white grid lines
for k in range(1, 4):
    ax.axhline(k - 0.5, color='#FCFAF5', lw=4)
    ax.axvline(k - 0.5, color='#FCFAF5', lw=4)

for a in range(4):
    for b in range(4):
        c = int(M[a, b])
        pct = P[a, b]
        if c == 0:
            ax.text(b, a, '—', ha='center', va='center', fontsize=16, color='#B9AE97')
        else:
            dark = pct > 45
            tcol = '#FCFAF5' if dark else '#4A3B22'
            ax.text(b, a - 0.13, f'{pct:.0f}%', ha='center', va='center',
                    fontsize=21, fontweight='bold', color=tcol)
            ax.text(b, a + 0.22, f'{c} 队', ha='center', va='center',
                    fontsize=13, color=tcol)
        if a == b:  # diagonal emphasis: inset ring
            ax.add_patch(plt.Rectangle((b - 0.46, a - 0.46), 0.92, 0.92, fill=False,
                                       edgecolor='#4A3B22', lw=2.2, alpha=0.55))

# labels with medal chips
ax.set_xticks(range(4)); ax.set_yticks(range(4))
ax.set_xticklabels(['正赛\n' + b for b in BANDS], fontsize=13)
ax.set_yticklabels(['网络赛\n' + b for b in BANDS], fontsize=13)
ax.tick_params(length=0)
for i, mc in enumerate(MEDAL):
    ax.add_patch(plt.Rectangle((-0.46, i - 0.1), 0.12, 0.14, clip_on=False,
                               facecolor=mc, edgecolor='none'))
for spine in ax.spines.values():
    spine.set_visible(False)

ax.set_title('网络赛档 → 正赛档 转移矩阵', fontsize=19, pad=26, weight='bold', color='#3B3226')
fig.text(0.5, 0.905, f'行内百分比 · 括号内为队伍数 · n={n} 队 · 两边取最好 · 已剔除 EC-Final/总决赛与网络赛前1%',
         ha='center', fontsize=11.5, color='#8A7D63')
cb = fig.colorbar(im, ax=ax, shrink=0.72, pad=0.03)
cb.set_label('行内占比 %', fontsize=11)
cb.outline.set_visible(False)
fig.text(0.5, 0.015, '对角线加框 = 留在原档；颜色越深占比越高', ha='center', fontsize=10.5, color='#8A7D63')
fig.tight_layout()
fig.savefig('plots/matrix_4band_v2.png', dpi=130, bbox_inches='tight', facecolor='#FCFAF5')
plt.close(fig)
print('saved matrix_4band_v2.png')