import matplotlib.pyplot as plt
import numpy as np

# --- 1. 全局绘图设置 ---
# 设置中文字体，尝试使用'SimHei'，如果您的系统没有，可以换成 'Microsoft YaHei' 等
plt.rcParams['font.sans-serif'] = ['SimHei'] 
# 解决负号显示问题
plt.rcParams['axes.unicode_minus'] = False

# --- 2. 实验数据 ---
# 频率 v，单位为 10^14 Hz
v = np.array([8.214, 7.408, 6.879, 5.490, 5.196])
# 遏止电压 Ua，单位为 V
Ua = np.array([1.846, 1.456, 1.246, 0.700, 0.588])

# --- 3. 数据计算 ---
# 使用最小二乘法进行线性回归，得到斜率和截距
# 拟合方程为 Ua = k_plot * v + b
k_plot, b = np.polyfit(v, Ua, 1)

# 根据物理关系 h = e * k, 其中 k 是 Ua-ν 图的真实物理斜率 (单位 V·s)
# 我们绘制的图横坐标单位是 10^14 Hz, 因此图上斜率 k_plot 的单位是 V / (10^14 Hz)
# 真实物理斜率 k = k_plot / 10^14
k_physical = k_plot / 1e14

# 基本电荷 e, 单位 C
e = 1.602e-19 

# 计算普朗克常量 h，单位 J·s
h = e * k_physical

# --- 4. 准备绘图 ---
# 创建一个平滑的x轴数据用于绘制拟合直线
v_fit = np.linspace(min(v), max(v), 100)
# 计算对应的拟合y轴数据
Ua_fit = k_plot * v_fit + b

# 创建图表
plt.figure(figsize=(10, 7))

# 绘制原始数据点
plt.scatter(v, Ua, label='实验数据点', color='blue', zorder=5)
# 绘制线性拟合线
plt.plot(v_fit, Ua_fit, 'r-', label='线性拟合线', zorder=4)

# --- 5. 美化图表 ---
# 添加坐标轴标签，使用LaTeX语法显示上标
plt.xlabel('频率 $v$ / ($10^{14}$ Hz)', fontsize=14)
plt.ylabel('遏止电压 $U_a$ / V', fontsize=14)
plt.title('遏止电压与频率关系图 ($U_a-v$ 图)', fontsize=16)

# 在图上显示拟合方程和计算得到的斜率
# 注意：这里的斜率 k_plot 是图表上的斜率，不是物理斜率 k
equation_text = f'拟合方程: $U_a = {k_plot:.4f} \\cdot v {b:+.4f}$'
plt.text(5.3, 1.6, equation_text, fontsize=12, color='green')

# 添加图例和网格
plt.legend(fontsize=12)
plt.grid(True, linestyle='--', alpha=0.6)

# 保存图像文件
plt.savefig("Ua_vs_v_plot.png", dpi=300)

# --- 6. 在控制台输出计算结果 ---
print("--- 计算结果 ---")
# 题目要求的斜率 k = h/e，保留4位有效数字
print(f"Ua-v 直线斜率 k = h/e: {k_physical:.4g} V·s")
# 普朗克常量 h，保留4位有效数字
print(f"普朗克常量 h = ek: {h:.4g} J·s")
print("\n图表已生成并保存为 'Ua_vs_v_plot.png'")

# 显示图表
plt.show()