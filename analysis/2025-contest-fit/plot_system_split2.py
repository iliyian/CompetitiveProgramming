import json
import numpy as np
from collections import defaultdict
from scipy import stats as st
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

BANDS = ['前1%', '金区', '银区', '铜区', '铁区']
BKEY = 'top1 gold silver bronze iron'.split()
COLORS = {'top1': '#e91e8c', 'gold': '#FFD700', 'silver': '#b8b8b8',
          'bronze': '#cd7f32', 'iron': '#7f8c8d'}

# online side NOT split: best-of-3 across all three online contests per team
online_best = defaultdict(list)
onsite_by_team = defaultdict(list)
for p in pairs:
    k = (p['school'], tuple(p['members']))
    online_best[k].append(p['online_rank'] / p['online_N_valid'])
    onsite_by_team[k].append(p)

def build(name, site_set):
    op = []; sp = []; M = np.zeros((5, 5), int)
    for k, onsite in onsite_by_team.items():
        mine = [p for p in onsite if p['onsite'] in site_set]
        if not mine: continue
        ob = min(online_best[k])
        sb = min(p['onsite_rank'] / p['onsite_N_valid'] for p in mine)
        op.append(ob); sp.append(sb)
        M[band(ob), band(sb)] += 1
    op = np.array(op); sp = np.array(sp)
    yb = np.array([band(x) for x in op]); sz = np.array([band(x) for x in sp])
    ret = M.diagonal() / M.sum(1); null = M.sum(0) / M.sum()
    H = []
    for b in range(5):
        p = M[b] / M[b].sum(); p = p[p > 0]
        H.append(float(-(p * np.log(p)).sum() / np.log(5)))
    dev = np.abs(sp - op); sticky = dev <= 0.10
    bins = np.linspace(0, 1, 11); bx = []; byy = []
    for i in range(10):
        sel = (op >= bins[i]) & (op < bins[i + 1])
        if sel.sum() >= 20:
            bx.append((bins[i] + bins[i + 1]) / 2 * 100); byy.append(sticky[sel].mean() * 100)
    widths = [np.percentile(sp[yb == b], 90) - np.percentile(sp[yb == b], 10) for b in range(5)]
    rho = float(st.spearmanr(op, sp)[0])
    out = {'name': name, 'n_teams': int(M.sum()), 'M': M.astype(int).tolist(),
           'ret': (M.diagonal() / M.sum(1)).tolist(), 'null': null.tolist(), 'H': H,
           'rho': rho, 'widths': [w * 100 for w in widths],
           'op': op.tolist(), 'sp': sp.tolist()}
    json.dump(out, open(f'system_{name}_bestof3.json', 'w'))
    print(f"== {name}: teams={M.sum()} pooled ρ={rho:.3f}")
    print('   M rows=online cols=onsite'); print(M.astype(int))
    print('   retention', np.round(ret, 2).tolist(), 'null', np.round(null, 2).tolist())
    print('   entropy', [round(h, 2) for h in H])
    print('   widths(pp)', [round(w * 100) for w in widths])
    # ROC gold
    from sklearn.metrics import roc_curve, auc
    fpr, tpr, _ = roc_curve((sz <= 1).astype(int), -op)
    out['auc_top10'] = float(auc(fpr, tpr))
    fpr2, tpr2, _ = roc_curve((sz == 4).astype(int), -op)
    out['auc_top10_iron'] = float(1 - auc(fpr2, tpr2))
    print('   AUC top10:', round(out['auc_top10'], 3), '| iron(等价):', round(out['auc_top10_iron'], 3))
    return out, op, sp

icpc, op_i, sp_i = build('icpc', ICPC_SITE)
ccpc, op_c, sp_c = build('ccpc', CCPC_SITE)

# last-hour per system unchanged (already onsite-only) - reuse from previous run
lasthour = json.load(open('lasthour.json'))
def lh(lst):
    vals = []
    for b in range(5):
        l = np.array([r['last1'] for r in lst if band(r['pct']) == b])
        vals.append(l.mean())
    return vals
lh_i = lh([r for r in lasthour if r['slug'] in ICPC_SITE])
lh_c = lh([r for r in lasthour if r['slug'] in CCPC_SITE])

fig, axes = plt.subplots(2, 2, figsize=(15, 10))
x = np.arange(5); w = 0.38
ax = axes[0, 0]
ret_i = np.array(icpc['ret']) * 100; ret_c = np.array(ccpc['ret']) * 100
ax.bar(x - w / 2, ret_i, w, color='#3498db', alpha=0.85, label='ICPC正赛')
ax.bar(x + w / 2, ret_c, w, color='#e67e22', alpha=0.85, label='CCPC正赛')
ax.plot(x, np.array(icpc['null']) * 100, 'k--', lw=1.2, label='无信息基线')
for i in range(5):
    ax.text(i - w / 2, ret_i[i] + 1, f'{ret_i[i]:.0f}', ha='center', fontsize=10, color='#2471a3')
    ax.text(i + w / 2, ret_c[i] + 1, f'{ret_c[i]:.0f}', ha='center', fontsize=10, color='#af601a')
ax.set_xticks(x, BANDS, fontsize=12); ax.set_ylim(0, 100)
ax.set_ylabel('正赛落在同档的比例 (%)', fontsize=12)
ax.set_title('① 同档保留率', fontsize=13)
ax.legend(fontsize=10); ax.grid(alpha=0.25, axis='y')

ax = axes[0, 1]
for nm, dat, col in [('ICPC', icpc, '#3498db'), ('CCPC', ccpc, '#e67e22')]:
    op = np.array(dat['op']); sp = np.array(dat['sp'])
    dev = np.abs(sp - op); sticky = dev <= 0.10
    bins = np.linspace(0, 1, 11); bx = []; byy = []
    for i in range(10):
        sel = (op >= bins[i]) & (op < bins[i + 1])
        if sel.sum() >= 20:
            bx.append((bins[i] + bins[i + 1]) / 2 * 100); byy.append(sticky[sel].mean() * 100)
    ax.plot(bx, byy, 'o-', color=col, lw=2, label=f"{nm} (n={dat['n_teams']})")
ax.axhline(34, color='gray', ls='--', lw=1)
ax.set_xticks(range(0, 101, 10)); ax.tick_params(labelsize=11); ax.set_ylim(0, 100)
ax.set_xlabel('网络赛三场最好百分位 (%)', fontsize=12)
ax.set_ylabel('正赛落在 ±10pp 内的比例 (%)', fontsize=12)
ax.set_title('② 粘滞窗口', fontsize=13)
ax.legend(fontsize=10); ax.grid(alpha=0.25)

ax = axes[1, 0]
Hi = np.array(icpc['H']) * 100; Hc = np.array(ccpc['H']) * 100
ax.bar(x - w / 2, Hi, w, color='#3498db', alpha=0.85, label='ICPC')
ax.bar(x + w / 2, Hc, w, color='#e67e22', alpha=0.85, label='CCPC')
for i in range(5):
    ax.text(i - w / 2, Hi[i] + 1, f'{Hi[i]:.0f}', ha='center', fontsize=10, color='#2471a3')
    ax.text(i + w / 2, Hc[i] + 1, f'{Hc[i]:.0f}', ha='center', fontsize=10, color='#af601a')
ax.set_xticks(x, BANDS, fontsize=12); ax.set_ylim(0, 100)
ax.set_ylabel('归一化条件熵 ×100', fontsize=12)
ax.set_title('③ 条件熵（0=确定, 100=纯随机）', fontsize=13)
ax.legend(fontsize=10); ax.grid(alpha=0.25, axis='y')

ax = axes[1, 1]
ax.plot(range(5), lh_i if False else lh_i, 'o-', color='#3498db', lw=2, label='ICPC')
ax.plot(range(5), lh_c, 's-', color='#e67e22', lw=2, label='CCPC')
ax.set_xticks(range(5), BANDS, fontsize=12)
ax.set_ylabel('末小时平均过题数', fontsize=12)
ax.set_title('④ 末小时过题 vs 水平（分体系）', fontsize=13)
ax.legend(fontsize=10); ax.grid(alpha=0.25, axis='y')
fig.suptitle('ICPC正赛 vs CCPC正赛（网络赛统一取三场最好, 不分体系）', fontsize=15, y=1.02)
fig.tight_layout(); fig.savefig('plots/system_split2.png', dpi=115, bbox_inches='tight'); plt.close(fig)
print('saved system_split2.png')