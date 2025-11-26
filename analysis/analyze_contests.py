import pandas as pd
import math
import matplotlib.pyplot as plt
import numpy as np
from scipy import stats
from scipy.optimize import curve_fit
from matplotlib.backends.backend_pdf import PdfPages
from collections import defaultdict
plt.rcParams['font.sans-serif'] = ['SimHei', 'DejaVu Sans', 'Arial']  # Use chinese font
plt.rcParams['axes.unicode_minus'] = False

def get_team_key(row):
    # 生成队伍关键字：学校 + 成员名字集合
    members = [row['Member1'], row['Member2'], row['Member3']]
    members = [m for m in members if pd.notna(m)]
    members.sort()
    # 加入学校名到关键字
    school = str(row['School'])
    key = school + '#' + '#'.join(sorted(members))
    return key

# 加载网络赛数据
online1 = pd.read_excel('The 49th ICPC Asia Regionals Online Contest (I).xlsx', header=1)
online2 = pd.read_excel('The 49th ICPC Asia Regionals Online Contest (II).xlsx', header=1)
online3 = pd.read_excel('第十届中国大学生程序设计竞赛网络预选赛.xlsx', header=1)

# 构建队伍网络赛表现映射，只包含解出一题以上的队伍
team_online = {}
for idx, row in online1.iterrows():
    if row['Solved'] > 0:
        key = get_team_key(row)
        team_online.setdefault(key, {})
        team_online[key]['rank1'] = row['Rank']

for idx, row in online2.iterrows():
    if row['Solved'] > 0:
        key = get_team_key(row)
        team_online.setdefault(key, {})
        team_online[key]['rank2'] = row['Rank']
        
for idx, row in online3.iterrows():
    if row['Solved'] > 0:
        key = get_team_key(row)
        team_online.setdefault(key, {})
        team_online[key]['rank3'] = row['Rank']

# 计算每个队伍的最佳网络赛排名
online_ranks = {}
for key, ranks in team_online.items():
    available_ranks = [r for r in ranks.values() if pd.notna(r)]
    if available_ranks:
        online_ranks[key] = min(available_ranks)

# 区域赛文件列表（包括ICPC和CCPC）
regional_files = [
    '第 49 届 ICPC 国际大学生程序设计竞赛区域赛成都站 - 正式赛.xlsx',
    '第 49 届 ICPC 国际大学生程序设计竞赛区域赛杭州站 - 正式赛.xlsx',
    '第 49 届 ICPC 国际大学生程序设计竞赛区域赛昆明站 - 正式赛.xlsx',
    '第 49 届 ICPC 国际大学生程序设计竞赛区域赛南京站 - 正式赛.xlsx',
    '第 49 届 ICPC 国际大学生程序设计竞赛区域赛上海站 - 正式赛.xlsx',
    '第 49 届 ICPC 国际大学生程序设计竞赛区域赛沈阳站 - 正式赛.xlsx',
    '第 10 届 CCPC 中国大学生程序设计竞赛重庆站 - 正式赛.xlsx',
    '第 10 届 CCPC 中国大学生程序设计竞赛哈尔滨站 - 正式赛.xlsx',
    '第 10 届 CCPC 中国大学生程序设计竞赛济南站 - 正式赛.xlsx',
    '第 10 届 CCPC 中国大学生程序设计竞赛郑州站 - 正式赛.xlsx'
]

# 去重
regional_files = list(set(regional_files))
regional_files.sort()

results = []
all_fit_data_icpc = []
all_fit_data_ccpc = []

for regional_file in regional_files:
    regional = pd.read_excel(regional_file, header=1)
    
    unofficial_mask = (regional['Unofficial'].fillna('') != 'Y')

    # 构建完整的 valid_mask
    valid_mask = (regional['Solved'] > 0) & \
                unofficial_mask & \
                pd.notna(regional['Rank'])

    valid_indices = regional.index[valid_mask]

    # 拟合数据收集
    fit_data = []
    valid_teams = len(valid_indices)
    rnk = 0
    for idx in valid_indices:
        rnk += 1
        row = regional.loc[idx]
        key = get_team_key(row)
        on_rank = online_ranks.get(key)
        if on_rank is not None:
            rank = rnk
            pct = (rank - 1) / (valid_teams - 1) * 100
            fit_data.append((on_rank, rank, pct, valid_teams, key, row['School']))

    # 有效队伍：至少解出一题的正式队伍
    fit_stats = {}
    if len(fit_data) > 5:
        on_r, reg_r, _, _, _, _ = zip(*fit_data)
        slope, intercept, r_value, p_value, std_err = stats.linregress(on_r, reg_r)
        fit_stats = {'slope': slope, 'intercept': intercept, 'r2': r_value**2, 'p': p_value}
        if 'ICPC' in regional_file:
            all_fit_data_icpc.extend(fit_data)
        else:
            all_fit_data_ccpc.extend(fit_data)
    if valid_teams == 0:
        continue
    # 金牌：有效队伍/10 向上取整
    gold_count = math.ceil(valid_teams / 10)
    # 银牌：金牌两倍
    silver_count = 2 * gold_count
    # 铜牌：三倍
    bronze_count = 3 * gold_count

    # 收集获牌队伍的网络赛排名
    medal_teams = {'gold': [], 'silver': [], 'bronze': []}

    rnk = 0
    for idx in valid_indices:
        row = regional.loc[idx]
        school = row['School']
        team_name = row['Team']
        key = get_team_key(row)
        online_rank = online_ranks.get(key, None)
        if online_rank is None:
            continue  # 只考虑有网络赛排名的
        rnk += 1
        rank = rnk
        team_info = (school, team_name, online_rank)
        if rank <= gold_count:
            medal_teams['gold'].append(team_info)
        elif rank <= gold_count + silver_count:
            medal_teams['silver'].append(team_info)
        elif rank <= gold_count + silver_count + bronze_count:
            medal_teams['bronze'].append(team_info)

    # 计算统计
    contest_stats = {}
    worst_teams = {}
    for medal, team_list in medal_teams.items():
        if not team_list:
            contest_stats[medal] = {'best': None, 'worst': None, 'avg': None, 'median': None}
            worst_teams[medal] = None
        else:
            ranks = [t[2] for t in team_list]
            contest_stats[medal] = {
                'q25': np.percentile(ranks, 25),
                'q75': np.percentile(ranks, 75),
                'avg': sum(ranks) / len(ranks),
                'median': np.median(ranks)
            }

    results.append({
        'contest': regional_file,
        'valid_teams': valid_teams,
        'medal_counts': {'gold': gold_count, 'silver': silver_count, 'bronze': bronze_count},
        'stats': contest_stats,
        'fit_stats': fit_stats,
        'fit_data': fit_data
    })

# 输出结果到文件
with open('analysis_results.txt', 'w', encoding='utf-8') as f:
    f.write("# 比赛分析结果\n\n")
    f.write("## 网络赛与区域赛关系分析\n\n")
    f.write("队伍标识: 学校 + 成员姓名集合\n")
    f.write("金牌: ceil(有效队伍/10), 银牌: 金牌*2, 铜牌: 金牌*3\n\n")

    for res in results:
        f.write(f"## {res['contest']}\n\n")
        f.write(f"- **有效队伍**: {res['valid_teams']}\n")
        f.write(f"- **金牌数**: {res['medal_counts']['gold']}, **银牌数**: {res['medal_counts']['silver']}, **铜牌数**: {res['medal_counts']['bronze']}\n\n")
        f.write("| 奖牌 | 25%分位数 | 75%分位数 | 平均排名 | 中位数排名 |\n")
        f.write("|------|----------|----------|--------|---------|\n")
        for medal in ['gold', 'silver', 'bronze']:
            s = res['stats'][medal]
            if s['q25'] is not None:
                f.write(f"| {medal.title()} | {s['q25']:.1f} | {s['q75']:.1f} | {s['avg']:.2f} | {s['median']:.1f} |\n")
            else:
                f.write(f"| {medal.title()} | 无 | 无 | 无 | 无 |\n")
        if res['fit_stats']:
            fs = res['fit_stats']
            f.write("### Regression Analysis\n")
            f.write(f"Regional Rank = {fs['slope']:.4f} * Online Rank + {fs['intercept']:.2f}, R² = {fs['r2']:.3f}, p = {fs['p']:.4f}\n\n")
# 画图
import numpy as np

contests = [res['contest'] for res in results]
labels = []
for c in contests:
    if '区域赛' in c:
        label = c.split('区域赛')[1].split(' - ')[0] + ' (ICPC)'
    elif '竞赛' in c:
        label = c.split('竞赛')[1].split(' - ')[0] + ' (CCPC)'
    else:
        label = c.split(' - ')[0] + ' (?)'
    labels.append(label)

x = np.arange(len(labels))
width = 0.25

# 获取数据
q25_gold = [res['stats']['gold']['q25'] or 0 for res in results]
q25_silver = [res['stats']['silver']['q25'] or 0 for res in results]
q25_bronze = [res['stats']['bronze']['q25'] or 0 for res in results]

q75_gold = [res['stats']['gold']['q75'] or 0 for res in results]
q75_silver = [res['stats']['silver']['q75'] or 0 for res in results]
q75_bronze = [res['stats']['bronze']['q75'] or 0 for res in results]

avg_gold = [res['stats']['gold']['avg'] or 0 for res in results]
avg_silver = [res['stats']['silver']['avg'] or 0 for res in results]
avg_bronze = [res['stats']['bronze']['avg'] or 0 for res in results]

median_gold = [res['stats']['gold']['median'] or 0 for res in results]
median_silver = [res['stats']['silver']['median'] or 0 for res in results]
median_bronze = [res['stats']['bronze']['median'] or 0 for res in results]

# 创建子图
fig, axes = plt.subplots(4, 1, figsize=(14, 24))

# Q25
axes[0].bar(x - width, q25_gold, width, label='Gold', color='gold')
axes[0].bar(x, q25_silver, width, label='Silver', color='gray')
axes[0].bar(x + width, q25_bronze, width, label='Bronze', color='brown')
axes[0].set_title('Q25 Online Ranks for Medal Teams')
axes[0].set_ylabel('Q25 Online Rank')
axes[0].set_xticks(x)
axes[0].set_xticklabels(labels, rotation=45, ha='right')
axes[0].legend()

# Q75
axes[1].bar(x - width, q75_gold, width, label='Gold', color='gold')
axes[1].bar(x, q75_silver, width, label='Silver', color='gray')
axes[1].bar(x + width, q75_bronze, width, label='Bronze', color='brown')
axes[1].set_title('Q75 Online Ranks for Medal Teams')
axes[1].set_ylabel('Q75 Online Rank')
axes[1].set_xticks(x)
axes[1].set_xticklabels(labels, rotation=45, ha='right')
axes[1].legend()

# Avg
axes[2].bar(x - width, avg_gold, width, label='Gold', color='gold')
axes[2].bar(x, avg_silver, width, label='Silver', color='gray')
axes[2].bar(x + width, avg_bronze, width, label='Bronze', color='brown')
axes[2].set_title('Average Online Ranks for Medal Teams')
axes[2].set_ylabel('Average Online Rank')
axes[2].set_xticks(x)
axes[2].set_xticklabels(labels, rotation=45, ha='right')
axes[2].legend()

# Median
axes[3].bar(x - width, median_gold, width, label='Gold', color='gold')
axes[3].bar(x, median_silver, width, label='Silver', color='gray')
axes[3].bar(x + width, median_bronze, width, label='Bronze', color='brown')
axes[3].set_title('Median Online Ranks for Medal Teams')
axes[3].set_ylabel('Median Online Rank')
axes[3].set_xticks(x)
axes[3].set_xticklabels(labels, rotation=45, ha='right')
axes[3].legend()

plt.tight_layout()
plt.savefig('analysis_plot.png', dpi=150)
print("Plot saved to analysis_plot.png")

# Scatter plots in PDF
with PdfPages('scatter_plots.pdf') as pdf:
    for res in results:
        fig, ax = plt.subplots()
        if res['fit_data']:
            on_r, reg_r, _, _, _, schools = zip(*res['fit_data'])
            red_mask = [sch == "浙江工业大学" for sch in schools]
            red_on = [on for i, on in enumerate(on_r) if red_mask[i]]
            red_reg = [reg for i, reg in enumerate(reg_r) if red_mask[i]]
            other_on = [on for i, on in enumerate(on_r) if not red_mask[i]]
            other_reg = [reg for i, reg in enumerate(reg_r) if not red_mask[i]]
            ax.scatter(other_on, other_reg, alpha=0.6, color='blue')
            ax.scatter(red_on, red_reg, alpha=0.6, color='red')
            max_x = max(on_r) * 1.1 if on_r else 3000
            ax.set_xlim(0, max_x)
            # Linear Fit line
            slope, intercept = res['fit_stats']['slope'], res['fit_stats']['intercept']
            x_line = np.linspace(0, max_x, 100)
            y_line = slope * x_line + intercept
            ax.plot(x_line, y_line, color='red', label='Linear')
            # Logarithmic Fit line y = a + b * ln(c + x)
            on_r_arr = np.array(on_r)
            reg_r_arr = np.array(reg_r)
            # Avoid log of 0
            valid = on_r_arr >= 0  # allow 0 if c >0
            if valid.sum() > 3:
                def log_func(x, a, b, c):
                    return a + b * np.log(c + x)
                try:
                    popt, pcov = curve_fit(log_func, on_r_arr[valid], reg_r_arr[valid], p0=[0, 1, 1.1], bounds=([ -np.inf, -np.inf, 0.01], [np.inf, np.inf, np.inf]))
                    a_log, b_log, c_log = popt
                    x_line_log = np.linspace(0, max_x, 100)
                    y_line_log = a_log + b_log * np.log(c_log + x_line_log)
                    ax.plot(x_line_log, y_line_log, color='blue', label='Logarithmic')
                    residuals = reg_r_arr[valid] - log_func(on_r_arr[valid], *popt)
                    r2_log = 1 - np.sum(residuals**2) / np.sum((reg_r_arr[valid] - np.mean(reg_r_arr[valid]))**2)
                    slope_log = b_log
                    intercept_log = a_log
                    c_log_flag = c_log
                except Exception as e:
                    # print(f"Log fit failed: {e}")
                    r2_log = None
            ax.set_xlabel('Online Rank')
            ax.set_ylabel('Regional Rank')
            ax.set_title(res['contest'])
            ax.set_ylim(bottom=0, top=res['valid_teams'])
            r2 = res['fit_stats']['r2']
            text_str = f'Valid Teams: {res["valid_teams"]}'
            text_str += f'\nR_squared Linear = {r2:.3f}'
            slope = res['fit_stats']['slope']
            intercept = res['fit_stats']['intercept']
            text_str += f'\nLinear: y = {slope:.3f}x + {intercept:.1f}'
            if 'r2_log' in locals() and r2_log is not None:  # Check if log fit was performed
                text_str += f'\nR_Squared Log = {r2_log:.3f}'
                text_str += f'\nLog: y = {intercept_log:.1f} + {slope_log:.3f} * ln({c_log:.3f} + x)'
            ax.text(0.95, 0.05, text_str, transform=ax.transAxes, horizontalalignment='right', verticalalignment='bottom', fontsize=8)
            ax.legend()
        # Horizontal lines for medal cutoffs
        gold_line = res['medal_counts']['gold']
        silver_line = res['medal_counts']['gold'] + res['medal_counts']['silver']
        bronze_line = res['medal_counts']['gold'] + res['medal_counts']['silver'] + res['medal_counts']['bronze']
        ax.axhline(y=gold_line, color='gold', linestyle='--', linewidth=1)
        ax.axhline(y=silver_line, color='gray', linestyle='--', linewidth=1)
        ax.axhline(y=bronze_line, color='saddlebrown', linestyle='--', linewidth=1)
        plt.tight_layout()
        pdf.savefig()
        plt.close(fig)

    # Overall ICPC scatter plot
    if all_fit_data_icpc:
        fig, ax = plt.subplots(figsize=(10, 8))
        df_icpc = pd.DataFrame(all_fit_data_icpc, columns=['on', 'reg', 'pct', 'vt', 'key', 'school'])
        df_icpc = df_icpc.sort_values(by="pct", ascending=True)      
        df_icpc = df_icpc.drop_duplicates(subset='key', keep='first')
        reg_icpc_pct = df_icpc['pct'].tolist()
        on_icpc = df_icpc['on'].tolist()
        schools_icpc = df_icpc['school'].tolist()
        red_mask = [sch == "浙江工业大学" for sch in schools_icpc]
        red_on = [on for i, on in enumerate(on_icpc) if red_mask[i]]
        red_reg = [pct for i, pct in enumerate(reg_icpc_pct) if red_mask[i]]
        other_on = [on for i, on in enumerate(on_icpc) if not red_mask[i]]
        other_reg = [pct for i, pct in enumerate(reg_icpc_pct) if not red_mask[i]]
        ax.scatter(other_on, other_reg, alpha=0.6, color='blue')
        ax.scatter(red_on, red_reg, alpha=0.6, color='red')
        max_x_icpc = max(on_icpc) * 1.1 if on_icpc else 3000
        ax.set_xlim(0, max_x_icpc)

        # Horizontal lines for medal cutoffs at percentiles
        ax.axhline(y=10, color='gold', linestyle='--', linewidth=1)
        ax.axhline(y=30, color='gray', linestyle='--', linewidth=1)
        ax.axhline(y=60, color='saddlebrown', linestyle='--', linewidth=1)

        # ICPC Linear Fit
        icpc_slope, icpc_intercept = stats.linregress(on_icpc, reg_icpc_pct)[:2]
        x_line = np.linspace(0, max_x_icpc, 100)
        y_line = icpc_slope * x_line + icpc_intercept
        ax.plot(x_line, y_line, color='red', label='ICPC Linear')

        # ICPC Log Fit
        on_icpc_arr = np.array(on_icpc)
        reg_icpc_arr_pct = np.array(reg_icpc_pct)
        valid = on_icpc_arr >= 0
        if valid.sum() > 3:
            def log_func(x, a, b, c):
                return a + b * np.log(c + x)
            try:
                popt, _ = curve_fit(log_func, on_icpc_arr[valid], reg_icpc_arr_pct[valid], p0=[0, 1, 1.1], bounds=([ -np.inf, -np.inf, 0.01], [np.inf, np.inf, np.inf]))
                a_log, b_log, c_log = popt
                x_line_log = np.linspace(0, max_x_icpc, 100)
                y_line_log = a_log + b_log * np.log(c_log + x_line_log)
                ax.plot(x_line_log, y_line_log, color='blue', label='Logarithmic')
                residuals = reg_icpc_arr_pct[valid] - log_func(on_icpc_arr[valid], *popt)
                r2_log = 1 - np.sum(residuals**2) / np.sum((reg_icpc_arr_pct[valid] - np.mean(reg_icpc_arr_pct[valid]))**2)
                slope_log = b_log
                intercept_log = a_log
            except Exception:
                r2_log = None
        ax.set_xlabel('Online Rank')
        ax.set_ylabel('Regional Best Rank Percentile Per Team')
        ax.set_title('Overall ICPC Scatter Plot')
        ax.set_ylim(0, 100)
        icpc_r2 = stats.linregress(on_icpc, reg_icpc_pct)[2]**2
        text_str = f'ICPC Linear: y = {icpc_slope:.3f}x + {icpc_intercept:.1f}'
        if 'r2_log' in locals() and r2_log is not None:
            text_str += f'\nICPC Log: y = {intercept_log:.1f} + {slope_log:.3f} * ln({c_log:.3f} + x)'
        text_str += f'\nICPC Linear R_squared = {icpc_r2:.3f}'
        if 'r2_log' in locals() and r2_log is not None:
            text_str += f'\nICPC Log R_squared = {r2_log:.3f}'
        ax.text(0.95, 0.05, text_str, transform=ax.transAxes, horizontalalignment='right', verticalalignment='bottom', fontsize=8)
        ax.legend()
        pdf.savefig()
        plt.close(fig)

    # Overall CCPC scatter plot
    if all_fit_data_ccpc:
        fig, ax = plt.subplots(figsize=(10, 8))
        df_ccpc = pd.DataFrame(all_fit_data_ccpc, columns=['on', 'reg', 'pct', 'vt', 'key', 'school'])
        df_ccpc = df_ccpc.sort_values(by='pct', ascending=True)
          
        df_ccpc = df_ccpc.drop_duplicates(subset='key', keep='first')
        reg_ccpc_pct = df_ccpc['pct'].tolist()
        on_ccpc = df_ccpc['on'].tolist()
        schools_ccpc = df_ccpc['school'].tolist()
        red_mask = [sch == "浙江工业大学" for sch in schools_ccpc]
        red_on = [on for i, on in enumerate(on_ccpc) if red_mask[i]]
        red_reg = [pct for i, pct in enumerate(reg_ccpc_pct) if red_mask[i]]
        other_on = [on for i, on in enumerate(on_ccpc) if not red_mask[i]]
        other_reg = [pct for i, pct in enumerate(reg_ccpc_pct) if not red_mask[i]]
        ax.scatter(other_on, other_reg, alpha=0.6, color='blue')
        ax.scatter(red_on, red_reg, alpha=0.6, color='red')
        max_x_ccpc = max(on_ccpc) * 1.1 if on_ccpc else 3000
        ax.set_xlim(0, max_x_ccpc)

        # Horizontal lines for medal cutoffs at percentiles
        ax.axhline(y=10, color='gold', linestyle='--', linewidth=1)
        ax.axhline(y=30, color='gray', linestyle='--', linewidth=1)
        ax.axhline(y=60, color='saddlebrown', linestyle='--', linewidth=1)

        # CCPC Linear Fit
        ccpc_slope, ccpc_intercept = stats.linregress(on_ccpc, reg_ccpc_pct)[:2]
        x_line = np.linspace(0, max_x_ccpc, 100)
        y_line = ccpc_slope * x_line + ccpc_intercept
        ax.plot(x_line, y_line, color='red', label='CCPC Linear')

        # CCPC Log Fit
        on_ccpc_arr = np.array(on_ccpc)
        reg_ccpc_arr_pct = np.array(reg_ccpc_pct)
        valid = on_ccpc_arr >= 0
        if valid.sum() > 3:
            def log_func(x, a, b, c):
                return a + b * np.log(c + x)
            try:
                popt, _ = curve_fit(log_func, on_ccpc_arr[valid], reg_ccpc_arr_pct[valid], p0=[0, 1, 1.1], bounds=([ -np.inf, -np.inf, 0.01], [np.inf, np.inf, np.inf]))
                a_log, b_log, c_log = popt
                x_line_log = np.linspace(0, max_x_ccpc, 100)
                y_line_log = a_log + b_log * np.log(c_log + x_line_log)
                ax.plot(x_line_log, y_line_log, color='blue', label='Logarithmic')
                residuals = reg_ccpc_arr_pct[valid] - log_func(on_ccpc_arr[valid], *popt)
                r2_log = 1 - np.sum(residuals**2) / np.sum((reg_ccpc_arr_pct[valid] - np.mean(reg_ccpc_arr_pct[valid]))**2)
                slope_log = b_log
                intercept_log = a_log
            except Exception:
                r2_log = None
        ax.set_xlabel('Online Rank')
        ax.set_ylabel('Regional Best Rank Percentile Per Team')
        ax.set_title('Overall CCPC Scatter Plot')
        ax.set_ylim(0, 100)
        ccpc_r2 = stats.linregress(on_ccpc, reg_ccpc_pct)[2]**2
        text_str = f'CCPC Linear: y = {ccpc_slope:.3f}x + {ccpc_intercept:.1f}'
        if 'r2_log' in locals() and r2_log is not None:
            text_str += f'\nCCPC Log: y = {intercept_log:.1f} + {slope_log:.3f} * ln({c_log:.3f} + x)'
        text_str += f'\nCCPC Linear R_squared = {ccpc_r2:.3f}'
        if 'r2_log' in locals() and r2_log is not None:
            text_str += f'\nCCPC Log R_squared = {r2_log:.3f}'
        ax.text(0.95, 0.05, text_str, transform=ax.transAxes, horizontalalignment='right', verticalalignment='bottom', fontsize=8)
        ax.legend()
        pdf.savefig()
        plt.close(fig)

print("Scatter plots saved to scatter_plots.pdf")
