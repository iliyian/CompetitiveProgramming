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
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import roc_curve, auc

EX = {'icpc_50th_ecfinal', 'ccpc_final'}
pairs = [p for p in json.load(open('pairs_valid.json')) if p['onsite'] not in EX]
ICPC_ON = {'icpc_ec1', 'icpc_ec2'}
ICPC_SITE = {'icpc_50th_xian', 'icpc_50th_chengdu', 'icpc_50th_wuhan', 'icpc_50th_shenyang',
             'icpc_50th_nanjing', 'icpc_50th_shanghai', 'icpc_50th_hongkong'}
CCPC_ON = {'ccpc_online'}
CCPC_SITE = {'ccpc_11th_harbin', 'ccpc_11th_jinan', 'ccpc_11th_zhengzhou', 'ccpc_11th_chongqing'}

def band(x):
    if x < 0.01: return 0
    if x < 0.10: return 1
    if x < 0.30: return 2
    if x < 0.60: return 3
    return 4

BANDS = ['前1%', '金区', '银区', '铜区', '铁区']
BKEY = 'top1 gold silver bronze iron'
BKEY = BKEY.split(' ')
COLORS = {'top1': '#e91e8c', 'gold': '#FFD700', 'silver': '#b8b8b8',
          'bronze': '#cd7f32', 'iron': '#7f8c8d'}

def build(name, on_set, site_set):
    sub = [p for p in pairs if p['online'] in on_set and p['onsite'] in site_set and p['online_solved'] > 0]
    byteam = defaultdict(list)
    for p in sub:
        byteam[(p['school'], tuple(p['members']))].append(p)
    op = np.array([p['online_rank'] / p['online_N_valid'] for p in sub])
    sp = np.array([p['onsite_rank'] / p['onsite_N_valid'] for p in sub])
    yb = np.array([band(x) for x in op]); sz = np.array([band(x) for x in sp])
    M = np.zeros((5, 5), int)
    rows_best = []
    for k, v in byteam.items():
        ob = min(x['online_rank'] / x['online_N_valid'] for x in v)
        sb = min(x['onsite_rank'] / x['onsite_N_valid'] for x in v)
        rows_best.append((ob, sb))
    for ob, sb in rows_best:
        M[band(ob), band(sb)] += 1
    ret = M.diagonal() / M.sum(1)
    null = M.sum(0) / M.sum()
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
    rho_pool = float(__import__('scipy').stats.spearmanr(op, sp)[0])
    # per online contest spearman
    per = {}
    for o in sorted(on_set):
        po = np.array([p['online_rank'] / p['online_N_valid'] for p in sub if p['online'] == o])
        ps = np.array([p['onsite_rank'] / p['onsite_N_valid'] for p in sub if p['online'] == o])
        per[o] = (len(po), float(__import__('scipy').stats.spearmanr(po, ps)[0]))
    out = {'name': name, 'n_pairs': len(sub), 'n_teams': int(M.sum()), 'M': M.tolist(),
           'ret': (M.diagonal() / M.sum(1)).tolist(), 'null': null.tolist(),
           'H': H, 'sticky_bins': [bx, byy], 'sticky_overall': float(sticky.mean()),
           'widths': [w * 100 for w in widths], 'rho_pool': rho_pool, 'per_online': per,
           'op': op.tolist(), 'sp': sp.tolist()}
    json.dump(out, open(f'system_{name}.json', 'w'))
    print(f"== {name}: pairs={len(sub)} teams={M.sum()} pooled ρ={rho_pool:.3f}")
    for o, (n_, r_) in per.items():
        print(f"   {o}: n={n_} ρ={r_:.3f}")
    print('   retention', np.round(ret, 2).tolist(), 'null', np.round(null, 2).tolist())
    print('   entropy', [round(h, 2) for h in H])
    print('   sticky bins', [round(y) for y in byy], 'overall', round(sticky.mean() * 100))
    print('   widths(pp)', [round(w * 100) for w in widths])
    return out

icpc = build('icpc', ICPC_ON, ICPC_SITE)
ccpc = build('ccpc', CCPC_ON, CCPC_SITE)

# ---- last-hour split by system
lasthour = json.load(open('lasthour.json'))
ICPC_SITES = ICPC_SITE; CCPC_SITES = CCPC_SITE
def band(p): return band if False else (0 if p < 0.01 else (1 if p < 0.10 else (2 if p < 0.30 else (3 if p < 0.60 else 4))))
lh_icpc = [r for r in lasthour if r['slug'] in ICPC_SITES]
lh_ccpc = [r for r in lasthour if r['slug'] in CCPC_SITE]
print('== last-hour by system')
for nm, lst in [('ICPC', lh_icpc if False else lh_ccpc if False else lh_icpc), ]:
    pass
for nm, lst in [('ICPC', lh_icpc), ('CCPC', lh_ccpc)]:
    out = []
    for b in range(5):
        l = np.array([r['last1'] for r in lst if band(r['pct']) == b])
        out.append((len(l), l.mean(), np.mean(l > 0) * 100))
    print(nm, ' '.join(f"{BANDS[i]}:{n}队 均{m:.2f} 有AC{p:.0f}%" for i, (n, m, p) in enumerate(out)))

# ---- figure
fig, axes = plt.subplots(2, 2, figsize=(15, 10))
ax = axes[0, 0]; x = np.arange(5); w = 0.38
ret_i = np.array(icpc['ret']) * 100; ret_c = np.array(ccpc['ret']) * 100
null_i = np.array(icpc['null']) * 100
ax.bar(x - w / 2, ret_i, w, color='#3498db', alpha=0.85, label='ICPC体系')
ax.bar(x + w / 2, ret_c, w, color='#e67e22', alpha=0.85, label='CCPC体系')
ax.plot(x, null_i if False else np.array(icpc['null']) * 100, 'k--', lw=1.2, label='无信息基线')
for i in range(5):
    ax.text(i - w / 2, ret_i[i] + 1, f'{ret_i[i]:.0f}', ha='center', fontsize=10, color='#2471a3')
    ax.text(i + w / 2, ret_c[i] + 1, f'{ret_c[i]:.0f}', ha='center', fontsize=10, color='#af601a')
ax.set_xticks(x, BANDS, fontsize=12); ax.set_ylim(0, 100)
ax.set_ylabel('正赛落在同档的比例 (%)', fontsize=12)
ax.set_title('① 同档保留率（基线=黑框空心）', fontsize=13)
ax.legend(fontsize=10); ax.grid(alpha=0.25, axis='y')

ax = axes[0, 1]
bi, ci = icpc['sticky_bins'], ccpc['sticky_bins']
ax.plot(bi[0], bi[1], 'o-', color='#3498db', lw=2, label=f"ICPC (n={icpc['n_pairs']})")
ax.plot(ci[0], ci[1], 's-', color='#e67e22', lw=2, label=f"CCPC (n={ccpc['n_pairs']})")
ax.axhline(34, color='gray', ls='--', lw=1)
ax.set_xticks(range(0, 101, 10)); ax.tick_params(labelsize=11); ax.set_ylim(0, 100)
ax.set_xlabel('网络赛百分位 (%)', fontsize=12)
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
ax.set_title('③ 条件熵（0=确定,100=纯随机）', fontsize=13)
ax.legend(fontsize=10); ax.grid(alpha=0.25, axis='y')

ax = axes[1, 1]
for nm, lst, col in [('ICPC', lh_icpc, '#3498db'), ('CCPC', lh_ccpc, '#e67e22')]:
    vals = []
    for b in range(5):
        l = np.array([r['last1'] for r in lst if band(r['pct']) == b])
        vals.append(l.mean())
    ax.plot(range(5), vals, 'o-', color=col, lw=2, label=nm)
ax.set_xticks(range(5), BANDS, fontsize=12)
ax.set_ylabel('末小时平均过题数', fontsize=12)
ax.set_title('④ 末小时过题 vs 水平（分体系）', fontsize=13)
ax.legend(fontsize=10); ax.grid(alpha=0.25, axis='y')
fig.suptitle('ICPC体系 vs CCPC体系分开对照（正式赛, 网络赛0解题对已剔除）', fontsize=15, y=1.02)
fig.tight_layout(); fig.savefig('plots/system_split.png', dpi=115, bbox_inches='tight'); plt.close(fig)
print('saved system_split.png')