import json
import numpy as np
from scipy import stats as st
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['WenQuanYi Zen Hei']
plt.rcParams['font.size'] = 13
plt.rcParams['axes.unicode_minus'] = False

slugs = ['icpc_50th_xian', 'icpc_50th_chengdu', 'icpc_50th_wuhan', 'icpc_50th_shenyang',
         'icpc_50th_nanjing', 'icpc_50th_shanghai', 'icpc_50th_hongkong',
         'ccpc_11th_harbin', 'ccpc_11th_jinan', 'ccpc_11th_zhengzhou', 'ccpc_11th_chongqing']
rows = []
for slug in slugs:
    cfg = json.load(open(f'data/{slug}_config.json'))
    dur = (cfg['end_time'] - cfg['start_time']) / 60000.0
    firstac = {}
    for r in json.load(open(f'data/{slug}_run.json')):
        if r['status'] in ('ACCEPTED', 'CORRECT'):
            k = (r['team_id'], r['problem_id'])
            if k not in firstac or r['timestamp'] < firstac[k]:
                firstac[k] = r['timestamp']
    fac = {}
    for (tid, pid), ts in firstac.items():
        if tid not in fac or ts < fac[tid]:
            fac[tid] = ts
    st_rows = json.load(open(f'{slug}_standings.json'))
    official = [t for t in st_rows if 'official' in t['groups'] and t['solved'] > 0]
    N = len(official)
    for t in official:
        if t['id'] in fac:
            rows.append({'slug': slug, 'pct': t['rank'] / N, 'solved': t['solved'],
                         'first_ac_min': fac[t['id']] / 60000.0})
json.dump(rows, open('firstac.json', 'w'), ensure_ascii=False)
fac = np.array([r['first_ac_min'] for r in rows])
pct = np.array([r['pct'] for r in rows])
solved = np.array([r['solved'] for r in rows])
print('n =', len(rows))
print('Spearman(首题时间, 名次百分位):', round(st.spearmanr(fac, pct)[0], 3))
def band(p): return 0 if p < 0.01 else (1 if p < 0.10 else (2 if p < 0.30 else (3 if p < 0.60 else 4)))
BANDS = ['前1%', '金区', '银区', '铜区', '铁区']
print('按档: 中位首题时间(min) / 30分钟内首AC比例')
for i in range(5):
    sel = np.array([band(p) == i for p in pct])
    d = fac[sel]
    print(f'  {BANDS[i]:3s} n={sel.sum():5d} 中位={np.median(d):5.1f}min 平均={d.mean():5.1f} 30min内={np.mean(d<=30)*100:4.1f}% 60min内={np.mean(d<=60)*100:4.1f}%')
# control by solved count: within solved==5, correlation
print('控制过题数后（同过题数组内）:')
for s in sorted(set(solved)):
    if s < 3: continue
    sel = solved == s
    if sel.sum() < 100: continue
    print(f'  solved={s}: n={sel.sum():4d} Spearman(首题,百分位)={st.spearmanr(fac[sel], pct[sel])[0]:.3f}')

fig, axes = plt.subplots(1, 2, figsize=(14.5, 6))
MEDAL = ['#e91e8c', '#D4A017', '#9E9E9E', '#B26A2B', '#6E7F80']
CREAM = '#FCFAF5'
fig.patch.set_facecolor(CREAM)
ax = axes[0]
groups = [fac[np.array([band(p) == i for p in pct])] for i in range(5)]
bp = ax.boxplot(groups, positions=range(5), widths=0.55, patch_artist=True, showfliers=False,
                medianprops=dict(color='k', lw=2))
for p, c in zip(bp['boxes'], MEDAL):
    p.set_facecolor(c); p.set_alpha(0.5)
for i, g in enumerate(groups):
    ax.text(i, -6, f'30min内 {np.mean(g<=30)*100:.0f}%', ha='center', fontsize=10.5, color=MEDAL[i])
ax.set_xticks(range(5), ['前1%', '金区\n1~10%', '银区\n10~30%', '铜区\n30~60%', '铁区\n>60%'], fontsize=12)
ax.set_ylabel('首题 AC 时间 (分钟)', fontsize=12)
ax.set_title('首题时间 vs 档位', fontsize=13)
ax.set_ylim(-10, None); ax.grid(alpha=0.25, axis='y')

ax = axes[1]
ax.scatter(fac, pct * 100, s=8, alpha=0.2, color='#5dade2', edgecolors='none')
bins = np.linspace(0, 300, 16)
xs = []; ys = []
for i in range(len(bins) - 1):
    sel = (fac >= bins[i]) & (fac < bins[i + 1])
    if sel.sum() >= 25:
        xs.append((bins[i] + bins[i + 1]) / 2); ys.append(np.median(pct[sel]) * 100)
ax.plot(xs, ys, 'o-', color='#e74c3c', lw=2, label='分箱中位')
ax.axhline(10, color='#D4A017', ls=':', lw=1, alpha=0.8)
ax.axhline(60, color='#B26A2B', ls=':', lw=1, alpha=0.8)
ax.set_xlabel('首题 AC 时间 (分钟)', fontsize=12)
ax.set_ylabel('正赛排名百分位 (%)', fontsize=12)
ax.set_title('首题时间 vs 名次百分位', fontsize=13)
ax.invert_yaxis()
ax.text(0.97, 0.95, f'Spearman ρ={st.spearmanr(fac, pct)[0]:.2f}', transform=ax.transAxes,
        ha='right', va='top', fontsize=11, color='#e74c3c')
ax.legend(fontsize=10, loc='lower right'); ax.grid(alpha=0.25)
fig.suptitle('首题 AC 时间 vs 队伍水平（11场正式赛, n=%d）' % len(rows), fontsize=15, y=1.02)
fig.tight_layout(); fig.savefig('plots/firstac.png', dpi=115, bbox_inches='tight', facecolor=CREAM); plt.close(fig)
print('saved firstac.png')