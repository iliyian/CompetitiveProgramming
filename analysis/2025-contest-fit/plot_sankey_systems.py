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
ICPC_SITE = {'icpc_50th_xian', 'icpc_50th_chengdu', 'icpc_50th_wuhan', 'icpc_50th_shenyang',
             'icpc_50th_nanjing', 'icpc_50th_shanghai', 'icpc_50th_hongkong'}
CCPC_SITE = {'ccpc_11th_harbin', 'ccpc_11th_jinan', 'ccpc_11th_zhengzhou', 'ccpc_11th_chongqing'}

def band(x):
    if x < 0.01: return 0
    if x < 0.10: return 1
    if x < 0.30: return 2
    if x < 0.60: return 3
    return 4

BANDS = ['金区 1~10%', '银区 10~30%', '铜区 30~60%', '铁区 >60%']
COLORS = {'gold': '#D4A017', 'silver': '#9E9E9E', 'bronze': '#B26A2B', 'iron': '#6E7F80'}
KEYS = ['gold', 'silver', 'bronze', 'iron']

online_best = defaultdict(list)
onsite_by_team = defaultdict(list)
for p in pairs:
    k = (p['school'], p['online_team'])
    online_best[k].append(p['online_rank'] / p['online_N_valid'])
    onsite_by_team[k].append(p)

print('=== 网络赛银区(10~30%) 但正赛进入金区(前10%) ===')
for name, site_set in [('ICPC', ICPC_SITE), ('CCPC', CCPC_SITE)]:
    for k, plist in onsite_by_team.items():
        mine = [p for p in plist if p['onsite'] in site_set]
        if not mine: continue
        ob = min(online_best[k])
        sb_p = min(mine, key=lambda p: p['onsite_rank'] / p['onsite_N_valid'])
        sb = sb_p['onsite_rank'] / sb_p['onsite_N_valid']
        if 0.10 <= ob < 0.30 and sb < 0.10:
            best_on = min(plist, key=lambda p: p['online_rank'] / p['online_N_valid'])
            print(f"[{name}] {k[0]} 《{k[1]}》: 网络赛最好 第{best_on['online_rank']}/{best_on['online_N_valid']}({ob*100:.1f}%) -> {sb_p['onsite']} 第{sb_p['onsite_rank']}/{sb_p['onsite_N_valid']}({sb*100:.1f}%)《{sb_p['onsite_team']}》 队员:{','.join(sb_p['members'])}")

sysd = {s: json.load(open(f'system_{s}_bestof3.json')) for s in ['icpc', 'ccpc']}
def to4(M):
    M = np.array(M)
    rows = M[1:]
    gold = rows[:, [1]] + rows[:, [0]]
    return np.hstack([gold, rows[:, 2:5]])

for s, title in [('icpc', 'ICPC 体系'), ('ccpc', 'CCPC 体系')]:
    F = to4(sysd[s]['M'])
    n_tot = int(F.sum())
    lh = F.sum(1); rh = F.sum(0)
    fig, ax = plt.subplots(figsize=(11.5, 7.5))
    H = 10.0; pad = 0.6
    ax.set_xlim(0, 1); ax.set_ylim(-0.6, H + 1.0); ax.axis('off')
    fig.patch.set_facecolor('#FCFAF5'); ax.set_facecolor('#FCFAF5')
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
            c = F[a, b]
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
    ax.text(0.25, H + 0.45, '网络赛(三场取最好)', ha='right', va='center', fontsize=14, weight='bold', color='#3B3226')
    ax.text(0.75, H + 0.45, '正赛(各场取最好)', ha='left', va='center', fontsize=14, weight='bold', color='#3B3226')
    ax.set_title(f'{title}：网络赛区间 → 正赛区间（n={n_tot}队）', fontsize=15, pad=16, color='#3B3226')
    fig.tight_layout(); fig.savefig(f'plots/sankey_{s}_4band.png', dpi=115, bbox_inches='tight', facecolor='#FCFAF5'); plt.close(fig)
    print(f'saved sankey_{s}_4band.png', F.tolist())