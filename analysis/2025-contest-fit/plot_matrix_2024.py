import json
import numpy as np
import pandas as pd
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.colors import LinearSegmentedColormap
plt.rcParams['font.sans-serif'] = ['WenQuanYi Zen Hei']
plt.rcParams['font.size'] = 13
plt.rcParams['axes.unicode_minus'] = False

BASE = 'data2024/'
ONLINE = [('icpc_ec1', 'The_49th_ICPC_Asia_Regionals_Online_Contest_I.xlsx'),
          ('icpc_ec2', 'The_49th_ICPC_Asia_Regionals_Online_Contest_II.xlsx'),
          ('ccpc_online', '第十届中国大学生程序设计竞赛网络预选赛.xlsx')]
ONSITE = {'icpc': ['第49届ICPC上海站_正式赛.xlsx', '第49届ICPC南京站_正式赛.xlsx',
                   '第49届ICPC成都站_正式赛.xlsx', '第49届ICPC昆明站_正式赛.xlsx',
                   '第49届ICPC杭州站_正式赛.xlsx', '第49届ICPC沈阳站_正式赛.xlsx'],
          'ccpc': ['第10届CCPC哈尔滨站_正式赛.xlsx', '第10届CCPC济南站_正式赛.xlsx',
                   '第10届CCPC郑州站_正式赛.xlsx', '第10届CCPC重庆站_正式赛.xlsx']}

def norm(s):
    s = str(s or '').strip().replace('（', '(').replace('）', ')')
    return ''.join(s.split())

def mkey(school, members):
    ms = tuple(sorted(norm(m) for m in members if str(m) != 'nan' and str(m).strip()))
    return (norm(school), ms)

def load_online():
    per = {}
    for slug, f in ONLINE:
        df = pd.read_excel(BASE + f, header=1)
        df = df.dropna(subset=['School', 'Rank'])
        valid = df[df['Solved'] > 0]
        nv = len(valid)
        for _, r in valid.iterrows():
            k = mkey(r['School'], [r.get('Member1'), r.get('Member2'), r.get('Member3')])
            if k in per.get(slug, {}):
                per.setdefault(slug, {})[k] = min(per[slug][k], float(r['Rank']) / nv)
            else:
                per.setdefault(slug, {})[k] = float(r['Rank']) / nv
        per[slug + '_N'] = nv
    return per

def load_onsite():
    out = {}
    for sysname, files in ONSITE.items():
        for f in files:
            df = pd.read_excel(BASE + f, header=1)
            df = df.dropna(subset=['School', 'Rank'])
            official = df[df['Unofficial'].fillna('N').astype(str).str.upper() != 'Y']
            valid = official[official['Solved'] > 0]
            nv = len(valid)
            teams = {}
            for _, r in valid.iterrows():
                k = mkey(r['School'], [r.get('Member1'), r.get('Member2'), r.get('Member3')])
                info = {'rank': float(r['Rank']), 'team': str(r['Team']), 'sys': sysname,
                        'file': f, 'N': nv}
                if k in teams:
                    teams[k] = min(teams[k], info, key=lambda x: x['rank'])
                else:
                    teams[k] = info
            out[f] = {'sys': sysname, 'N': nv, 'teams': teams}
    return out

def band4(x):
    if x < 0.10: return 0
    if x < 0.30: return 1
    if x < 0.60: return 2
    return 3

on = load_online()
site = load_onsite()
online_best = {}
for slug, _ in ONLINE:
    for k, rk in on[slug].items():
        online_best.setdefault(k, []).append(rk)
online_best = {k: min(v) for k, v in online_best.items()}

BANDS = ['金区 1~10%', '银区 10~30%', '铜区 30~60%', '铁区 >60%']
MEDAL = ['#D4A017', '#9E9E9E', '#B26A2B', '#6E7F80']
cmap = LinearSegmentedColormap.from_list(
    'amber', ['#FBF8F1', '#F0E3C4', '#DFC27E', '#C9963F', '#8F6119'])

def render(M, name, subtitle, fname):
    n = int(M.sum())
    P = M / M.sum(1, keepdims=True) * 100
    fig, ax = plt.subplots(figsize=(9.8, 7.6))
    fig.patch.set_facecolor('#FCFAF5'); ax.set_facecolor('#FCFAF5')
    im = ax.imshow(P, cmap=cmap, vmin=0, vmax=100, aspect='auto')
    for k in range(1, 4):
        ax.axhline(k - 0.5, color='#FCFAF5', lw=4)
        ax.axvline(k - 0.5, color='#FCFAF5', lw=4)
    for a in range(4):
        for b in range(4):
            c = int(M[a, b]); pct = P[a, b]
            if c == 0:
                ax.text(b, a, '—', ha='center', va='center', fontsize=16, color='#B9AE97')
            else:
                tcol = '#FCFAF5' if pct > 45 else '#4A3B22'
                ax.text(b, a - 0.13, f'{pct:.0f}%', ha='center', va='center',
                        fontsize=21, fontweight='bold', color=tcol)
                ax.text(b, a + 0.22, f'{c} 队', ha='center', va='center', fontsize=13, color=tcol)
            if a == b:
                ax.add_patch(plt.Rectangle((b - 0.46, a - 0.46), 0.92, 0.92, fill=False,
                                           edgecolor='#4A3B22', lw=2.2, alpha=0.55))
    ax.set_xticks(range(4)); ax.set_yticks(range(4))
    ax.set_xticklabels(['正赛\n' + b for b in BANDS], fontsize=13)
    ax.set_yticklabels(['网络赛\n' + b for b in BANDS], fontsize=13)
    ax.tick_params(length=0)
    for i, mc in enumerate(MEDAL):
        ax.add_patch(plt.Rectangle((-0.46, i - 0.1), 0.12, 0.14, clip_on=False,
                                   facecolor=mc, edgecolor='none'))
    for spine in ax.spines.values():
        spine.set_visible(False)
    ax.set_title(name, fontsize=19, pad=26, weight='bold', color='#3B3226')
    fig.text(0.5, 0.905, subtitle, ha='center', fontsize=11.5, color='#8A7D63')
    cb = fig.colorbar(im, ax=ax, shrink=0.72, pad=0.03)
    cb.set_label('行内占比 %', fontsize=11)
    cb.outline.set_visible(False)
    fig.text(0.5, 0.015, '对角线加框 = 留在原档；颜色越深占比越高', ha='center', fontsize=10.5, color='#8A7D63')
    fig.tight_layout()
    fig.savefig(fname, dpi=130, bbox_inches='tight', facecolor='#FCFAF5')
    plt.close(fig)
    ret = M.diagonal() / M.sum(1)
    print(name, 'n=', n, 'retention', np.round(ret, 2).tolist())
    return ret

results = {}
for sysname in ['icpc', 'ccpc']:
    M = np.zeros((4, 4), int)
    dropped = 0
    # group onsite files of this system by team: best onsite percentile
    best_onsite = {}
    for f, info in site.items():
        if info['sys'] != sysname: continue
        for k, t in info['teams'].items():
            if k not in best_onsite or t['rank'] / t['N'] < best_onsite[k][0] / best_onsite[k][1]:
                best_onsite[k] = (t['rank'], t['N'], t['team'], f)
    for k, (rk, nv, tname, f) in best_onsite.items():
        if k not in online_best:
            continue
        ob = online_best[k]
        if ob < 0.01:
            dropped += 1
            continue
        M[band4(ob), band4(rk / nv)] += 1
    results[sysname] = {'M': M.astype(int).tolist(), 'dropped': dropped,
                        'n': int(M.sum()), 'ret': (M.diagonal() / M.sum(1)).tolist()}
    year = '2024'
    label = '第49届 ICPC' if sysname == 'icpc' else '第10届 CCPC'
    render(M, f'{label} 2024：网络赛档 → 正赛档 转移矩阵',
           ('6场区域赛' if sysname == 'icpc' else '4场分站赛') + ' · 行内百分比 · 括号内为队伍数 · 两边取最好',
           f'plots/matrix_2024_{sysname}.png')
    print('  dropped top1% online:', dropped)
    print(M.astype(int))

json.dump(results, open('matrix_2024_stats.json', 'w'), ensure_ascii=False)
print('saved matrix_2024_icpc.png / matrix_2024_ccpc.png')