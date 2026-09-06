import json
import numpy as np
from collections import defaultdict
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['WenQuanYi Zen Hei']
plt.rcParams['font.size'] = 13
plt.rcParams['axes.unicode_minus'] = False

pairs = [p for p in json.load(open('pairs_valid_no_finals.json')) if p['online_solved'] > 0]
byteam = defaultdict(list)
for p in pairs:
    byteam[(p['school'], tuple(p['members']))].append(p)

def band4(x):
    # online >=1% only; onsite <1% merged into gold
    if x < 0.10: return 0
    if x < 0.30: return 1
    if x < 0.60: return 2
    return 3

BANDS = ['金区 1~10%', '银区 10~30%', '铜区 30~60%', '铁区 >60%']
COLORS = {'gold': '#FFD700', 'silver': '#b8b8b8', 'bronze': '#cd7f32', 'iron': '#7f8c8d'}
KEYS = ['gold', 'silver', 'bronze', 'iron']

flows = np.zeros((4, 4), int)
n_tot = 0; dropped = 0
for k, v in byteam.items():
    cand = [x for x in v if x['online_solved'] > 0]
    if not cand: continue
    ob = min(x['online_rank'] / x['online_N_valid'] for x in cand)
    sb = min(x['onsite_rank'] / x['onsite_N_valid'] for x in v)
    if ob < 0.01:
        dropped += 1
        continue
    flows[band4(ob), band4(sb)] += 1
    n_tot += 1
print('kept', n_tot, 'dropped(top1% online)', dropped)
print(flows)
json.dump({'M': flows.tolist(), 'n': int(n_tot)}, open('zone_flow_4band.json', 'w'))

# ---- sankey
fig, ax = plt.subplots(figsize=(12, 8))
H = 10.0; pad = 0.6
ax.set_xlim(0, 1); ax.set_ylim(-0.6, H + 1.0); ax.axis('off')
lh = flows.sum(1); rh = flows.sum(0)
scale = (H - pad * 3) / n_tot
def layout(hs):
    pos = {}; top = H
    for i in range(4):
        h = hs[i] * scale; pos[i] = (top - h, top); top -= h + pad
    return pos
L = layout(lh); R = layout(rh)
lo = {i: L[i][0] for i in range(4)}; ro = {i: R[i][0] for i in range(4)}
ts = np.linspace(0, 1, 80)
for a in range(4):
    for b in range(4):
        c = flows[a, b]
        if c == 0: continue
        th = c * scale; lc = lo[a] + th / 2; rc = ro[b] + th / 2
        lo[a] += th; ro[b] += th
        ys = (1 - ts) ** 3 * lc + 3 * (1 - ts) ** 2 * ts * lc + 3 * (1 - ts) * ts ** 2 * rc + ts ** 3 * rc
        ax.fill_between(0.30 + 0.40 * ts, ys - th / 2, ys + th / 2, color=COLORS[KEYS[a]], alpha=0.42, linewidth=0)
for i in range(4):
    y0, y1 = L[i]; ax.add_patch(plt.Rectangle((0.255, y0), 0.03, y1 - y0, color=COLORS[KEYS[i]]))
    ax.text(0.24, (y0 + y1) / 2, f'{BANDS[i]}  {lh[i]}队', ha='right', va='center', fontsize=13)
    y0, y1 = R[i]; ax.add_patch(plt.Rectangle((0.715, y0), 0.03, y1 - y0, color=COLORS[KEYS[i]]))
    ax.text(0.755, (y0 + y1) / 2, f'{rh[i]}', ha='left', va='center', fontsize=13)
ax.text(0.25, H + 0.45, '网络赛(三场取最好, 前1%已剔除)', ha='right', va='center', fontsize=14, weight='bold')
ax.text(0.75, H + 0.45, '正赛(各场取最好, 前1%并入金区)', ha='left', va='center', fontsize=14, weight='bold')
ax.set_title(f'网络赛区间 → 正赛区间（金/银/铜/铁, n={n_tot}队, 两边取最好, 剔除EC-Final/总决赛）', fontsize=15, pad=16)
fig.tight_layout(); fig.savefig('plots/sankey_4band.png', dpi=115, bbox_inches='tight'); plt.close(fig)

# ---- matrix heatmap (row-normalized percentages + counts)
fig, ax = plt.subplots(figsize=(8.5, 7))
P = flows / flows.sum(1, keepdims=True) * 100
im = ax.imshow(P, cmap='RdYlGn_r', vmin=0, vmax=100)
ax.set_xticks(range(4), ['正赛\n'+b for b in BANDS], fontsize=12)
ax.set_yticks(range(4), ['网络赛\n'+b for b in BANDS], fontsize=12)
for a in range(4):
    for b in range(4):
        c = flows[a, b]
        if c == 0:
            ax.text(b, a, '-', ha='center', va='center', color='gray', fontsize=13)
        else:
            ax.text(b, a, f'{P[a,b]:.0f}%\n({c})', ha='center', va='center', fontsize=12,
                    color='k')
ax.set_title(f'网络赛档 → 正赛档 转移矩阵（行内百分比, 括号=队伍数, n={n_tot}）', fontsize=13, pad=12)
fig.colorbar(im, shrink=0.85, label='行内占比 %')
fig.tight_layout(); fig.savefig('plots/matrix_4band.png', dpi=120, bbox_inches='tight'); plt.close(fig)
print('saved sankey_4band.png / matrix_4band.png')