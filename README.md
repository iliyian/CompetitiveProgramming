## Competitive Programming

> 个人竞赛编程知识库 | Personal Competitive Programming Knowledge Base

[![Problems](https://img.shields.io/badge/Problems-1400%2B-blue)]()
[![Templates](https://img.shields.io/badge/Templates-115%2B-green)]()
[![Language](https://img.shields.io/badge/Language-C%2B%2B-orange)]()

---

## 目录 | Table of Contents

- [仓库概览 | Overview](#仓库概览--overview)
- [算法模板 | Templates](#算法模板--templates)
- [题解平台 | Online Judges](#题解平台--online-judges)
- [竞赛题解 | Contests](#竞赛题解--contests)
- [目录结构 | Structure](#目录结构--structure)

---

## 仓库概览 | Overview

| 统计项 | 数量 |
|--------|------|
| C++ 源文件 | 5000+ |
| Python 文件 | 80+ |
| 算法模板类别 | 115+ |
| 题解总数（各平台） | 1400+ |
| 覆盖在线评测平台 | 18+ |

---

## 算法模板 | Templates

模板位于 [`Templates/`](./Templates/) 目录，涵盖竞赛常用算法与数据结构。

### 数据结构 | Data Structures

| 模板 | 说明 |
|------|------|
| [seg](./Templates/seg/) | 线段树（区间加、区间最值、动态开点、线段树上二分等） |
| [fenwick](./Templates/fenwick/) | 树状数组 / 二叉索引树 |
| [主席树](./Templates/主席树/) | 可持久化线段树 |
| [dsu](./Templates/dsu/) | 并查集 |
| [带距离权并查集带路径压缩](./Templates/带距离权并查集带路径压缩/) | 带权并查集 |
| [fhqtreap.cpp](./Templates/fhqtreap.cpp) | FHQ Treap（无旋 Treap） |
| [SB树](./Templates/SB树/) | 替罪羊树 / Size-Balanced Tree |
| [pb_ds_tree](./Templates/pb_ds_tree/) | STL pb_ds 平衡树扩展 |
| [pb_ds可并堆](./Templates/pb_ds可并堆/) | 可并堆（左偏树） |
| [链表](./Templates/链表/) | 双向链表 |
| [笛卡尔树](./Templates/笛卡尔树/) | Cartesian Tree |
| [ST表](./Templates/ST表/) | Sparse Table（RMQ） |
| [分块](./Templates/分块/) | 根号分块 |

### 图论 | Graph Theory

| 模板 | 说明 |
|------|------|
| [dijkstra](./Templates/dijkstra/) | Dijkstra 最短路 |
| [SPFA](./Templates/SPFA/) | SPFA 最短路 |
| [SCC](./Templates/SCC/) | 强连通分量（Tarjan） |
| [bcc_bridge](./Templates/bcc_bridge/) | 点双连通分量 & 桥 |
| [cut_point](./Templates/cut_point/) | 割点 |
| [max-flow](./Templates/max-flow/) | 最大流（Dinic） |
| [min-cost](./Templates/min-cost/) | 最小费用流 |
| [min-cut](./Templates/min-cut/) | 最小割 |
| [hld](./Templates/hld/) | 重链剖分 |
| [LCA](./Templates/LCA/) | 最近公共祖先 |
| [欧拉序_O1_LCA](./Templates/欧拉序_O1_LCA/) | 欧拉序 O(1) LCA |
| [欧拉路](./Templates/欧拉路/) | 欧拉路 / 欧拉回路 |
| [tree_diameter](./Templates/tree_diameter/) | 树的直径 |
| [点分治](./Templates/点分治/) | 点分治 |
| [树上启发式合并](./Templates/树上启发式合并/) | DSU on Tree |
| [基环树](./Templates/基环树/) | 基环树 |
| [n点n边的基环树森林找环](./Templates/n点n边的基环树森林找环/) | 基环树森林找环 |
| [圆方树，点双](./Templates/圆方树，点双/) | 圆方树 |
| [bigraph-weight-match](./Templates/bigraph-weight-match/) | 二分图带权匹配（KM 算法） |
| [斯坦纳树](./Templates/斯坦纳树/) | Steiner Tree |
| [竞赛图找三元环](./Templates/竞赛图找三元环/) | 竞赛图三元环计数 |
| [2-sat](./Templates/2-sat/) | 2-SAT |
| [最大权闭合子图](./Templates/最大权闭合子图/) | 最大权闭合子图 |
| [dfs树性质](./Templates/dfs树性质/) | DFS 树性质 |
| [DFS](./Templates/DFS/) | DFS 相关 |
| [Kurskal](./Templates/Kurskal/) | Kruskal 最小生成树 |
| [secondary_mst](./Templates/secondary_mst/) | 次小生成树 |
| [扫描线](./Templates/扫描线/) | 扫描线 |
| [线段树优化建图](./Templates/线段树优化建图/) | 线段树优化建图 |
| [线段树或时间线分治](./Templates/线段树或时间线分治/) | 线段树分治 |

### 动态规划 | Dynamic Programming

| 模板 | 说明 |
|------|------|
| [DP](./Templates/DP/) | 经典 DP 合集（凸包优化 CHT、斜率优化等） |
| [knapsack](./Templates/knapsack/) | 背包 DP（0-1、完全、多重） |
| [数论分块](./Templates/数论分块/) | 整除分块 |
| [CDQ](./Templates/CDQ/) | CDQ 分治（三维偏序等） |
| [高维偏序](./Templates/高维偏序/) | 高维偏序 |
| [二维数点](./Templates/二维数点/) | 二维数点 |
| [离线](./Templates/离线/) | 离线算法 |
| [折半搜索](./Templates/折半搜索/) | Meet in the Middle |
| [IDAstar](./Templates/IDAstar/) | IDA* |
| [Astar](./Templates/Astar/) | A* |
| [反悔贪心](./Templates/反悔贪心/) | 反悔贪心 |
| [矩阵快速幂](./Templates/矩阵快速幂/) | 矩阵快速幂 |
| [lagrange_interpolation.cpp](./Templates/lagrange_interpolation.cpp) | 拉格朗日插值 |

### 数学 | Mathematics

| 模板 | 说明 |
|------|------|
| [FFT](./Templates/FFT/) | 快速傅里叶变换 |
| [ntt](./Templates/ntt/) | 数论变换 NTT |
| [Pollard_Rho_Miller_Rabin](./Templates/Pollard_Rho_Miller_Rabin/) | 大数分解 & 素性测试 |
| [prime_sieve](./Templates/prime_sieve/) | 素数筛（线性筛） |
| [分解质因数](./Templates/分解质因数/) | 质因数分解 |
| [euler_totient](./Templates/euler_totient/) | 欧拉函数 |
| [ex_euler](./Templates/ex_euler/) | 扩展欧拉定理 |
| [C_n_m_mod_p](./Templates/C_n_m_mod_p/) | 组合数取模（Lucas 定理） |
| [CRT](./Templates/CRT/) | 中国剩余定理 |
| [inverse_exgcd](./Templates/inverse_exgcd/) | 逆元 & 扩展 GCD |
| [gcd_lcm](./Templates/gcd_lcm/) | GCD & LCM |
| [fast_gcd.cpp](./Templates/fast_gcd.cpp) | 基于 Stein 优化的超快速 GCD |
| [基于stein优化的超快速gcd](./Templates/基于stein优化的超快速gcd/) | 同上 |
| [rational_mod](./Templates/rational_mod/) | 有理数取模 |
| [gauss](./Templates/gauss/) | 高斯消元 |
| [linear_equation](./Templates/linear_equation/) | 线性方程组 |
| [determinant](./Templates/determinant/) | 行列式 |
| [莫比乌斯反演](./Templates/莫比乌斯反演/) | Möbius 反演 |
| [catalan](./Templates/catalan/) | 卡特兰数 |
| [stirling](./Templates/stirling/) | 斯特林数 |
| [Big](./Templates/Big/) | 大数运算 |

### 字符串 | Strings

| 模板 | 说明 |
|------|------|
| [KMP](./Templates/KMP/) | KMP 字符串匹配 |
| [Z函数](./Templates/Z函数/) | Z 函数 |
| [AC自动机](./Templates/AC自动机/) | Aho-Corasick 自动机 |
| [01trie](./Templates/01trie/) | 01-Trie（异或最大最小） |
| [哈希](./Templates/哈希/) | 字符串哈希 |

### 几何 | Geometry

| 模板 | 说明 |
|------|------|
| [convex_hull](./Templates/convex_hull/) | 凸包 |
| [half-plane](./Templates/half-plane/) | 半平面交 |
| [曼哈顿和切比雪夫](./Templates/曼哈顿和切比雪夫/) | 曼哈顿距离 ↔ 切比雪夫距离转换 |
| [max_sub_rect](./Templates/max_sub_rect/) | 最大子矩形 |

### 其他 | Miscellaneous

| 模板 | 说明 |
|------|------|
| [ULTIMATE_IO.cpp](./Templates/ULTIMATE_IO.cpp) | 极速 I/O |
| [Read_Write](./Templates/Read_Write/) | 快读快写 |
| [basis](./Templates/basis/) | 线性基（异或基） |
| [mo-algorithm](./Templates/mo-algorithm/) | 莫队算法 |
| [三分](./Templates/三分/) | 三分搜索（整数域） |
| [ternary_search](./Templates/ternary_search/) | 三分搜索（实数域） |
| [尺取](./Templates/尺取/) | 双指针 / 滑动窗口 |
| [adjacent_diff](./Templates/adjacent_diff/) | 差分数组 |
| [二维差分与前缀和](./Templates/二维差分与前缀和/) | 二维差分 & 前缀和 |
| [动态二阶差分](./Templates/动态二阶差分/) | 动态二阶差分 |
| [dull_queue_stack](./Templates/dull_queue_stack/) | 单调队列 & 单调栈 |
| [lowbit应用](./Templates/lowbit应用/) | lowbit 应用 |
| [区间颜色数](./Templates/区间颜色数/) | 区间颜色数 |
| [区间包含](./Templates/interval_contain/) | 区间包含判断 |
| [interval_merge](./Templates/interval_merge/) | 区间合并 |
| [找可以作为最小值的区间，相同值不重叠](./Templates/找可以作为最小值的区间，相同值不重叠/) | 区间最小值 |
| [括号序列](./Templates/括号序列/) | 括号序列 |
| [二分图染色.cpp](./Templates/二分图染色.cpp) | 二分图判断 |
| [rings-count](./Templates/rings-count/) | 环计数 |
| [线段树套线性基](./Templates/线段树套线性基/) | 线段树套线性基 |
| [多叉树](./Templates/多叉树/) | 多叉树 |
| [discrete_typedsu_prefixsum](./Templates/discrete_typedsu_prefixsum/) | 离散化 + 并查集 + 前缀和 |
| [筛法](./Templates/筛法/) | 线性筛综合 |
| [二维树状数组](./Templates/二维树状数组/) | 二维树状数组 |
| [gen.py](./Templates/gen.py) | 数据生成器 |
| [quine.cpp](./Templates/quine.cpp) | Quine 程序 |

---

## 题解平台 | Online Judges

| 平台 | 题目数 | 目录 |
|------|--------|------|
| [Luogu 洛谷](https://www.luogu.com.cn/) | 655+ | [luogu.com.cn/](./luogu.com.cn/) |
| [Codeforces](https://codeforces.com/) | 608+ | [codeforces.com/](./codeforces.com/) |
| [AtCoder](https://atcoder.jp/) | 48+ | [atcoder.jp/](./atcoder.jp/) |
| [牛客竞赛](https://ac.nowcoder.com/) | 67+ | [ac.nowcoder.com/](./ac.nowcoder.com/) |
| [VJudge](https://vjudge.net/) | 51+ | [vjudge.net/](./vjudge.net/) |
| [HDU OJ](https://acm.hdu.edu.cn/) | 22+ | [acm.hdu.edu.cn/](./acm.hdu.edu.cn/) |
| [QOJ](https://qoj.ac/) | 27+ | [qoj.ac/](./qoj.ac/) |
| [PinTia 拼题 A](https://pintia.cn/) | 9+ | [pintia.cn/](./pintia.cn/) |
| [ZJUT OJ](https://zjutacm.cn/) | 11+ | [zjutacm.cn/](./zjutacm.cn/) |
| [ThemeCp](https://themecp.vercel.app/) | 21+ | [themecp.vercel.app/](./themecp.vercel.app/) |
| [Reach-Top](https://reach-top.cn/) | 16+ | [reach-top.cn/](./reach-top.cn/) |
| [Saikr](https://saikr.com/) | 4+ | [saikr.com/](./saikr.com/) |
| [Yukicoder](https://yukicoder.me/) | 3+ | [yukicoder.me/](./yukicoder.me/) |
| [ECNU OJ](https://acm.ecnu.edu.cn/) | 3+ | [acm.ecnu.edu.cn/](./acm.ecnu.edu.cn/) |
| [百度 AI Star](https://astar.baidu.com/) | 3+ | [astar.baidu.com/](./astar.baidu.com/) |
| [CSP](https://csp.ccf.org.cn/) | 3+ | [csp.ccf.org.cn/](./csp.ccf.org.cn/) |
| [代码源](https://daimayuan.top/) | 2+ | [daimayuan.top/](./daimayuan.top/) |
| [Kedacun](https://kedacun.ac/) | 3+ | [kedacun.ac/](./kedacun.ac/) |
| [BCPC](https://bcpc.net.cn/) | 1+ | [bcpc.net.cn/](./bcpc.net.cn/) |

---

## 竞赛题解 | Contests

| 竞赛 | 目录 |
|------|------|
| ICPC 2025 网络赛（赛 1） | [2025icpc1/](./2025icpc1/) |
| ICPC 2025 网络赛（赛 2） | [2025icpc2/](./2025icpc2/) |
| ICPC 2022 Hangzhou | [icpc2022hangzhou/](./icpc2022hangzhou/) |
| CCPC | [ccpc/](./ccpc/) |
| 天梯赛 2025 | [天梯赛2025/](./天梯赛2025/) |
| 2024 ZJUT 迎新赛预赛 | [2024ZJUT迎新赛预赛_A-M_satsky/](./2024ZJUT迎新赛预赛_A-M_satsky/) |
| 网络赛 | [网络赛/](./网络赛/) |
| Daily CF Problems | [Daily_CF_Problems/](./Daily_CF_Problems/) |
| Jiangly 模板参考 | [jiangly/](./jiangly/) |

---

## 目录结构 | Structure

```
CompetitiveProgramming/
├── Templates/              # 算法模板（115+ 类别）
├── codeforces.com/         # Codeforces 题解
├── luogu.com.cn/           # 洛谷题解
├── atcoder.jp/             # AtCoder 题解
├── ac.nowcoder.com/        # 牛客竞赛题解
├── vjudge.net/             # VJudge 题解
├── acm.hdu.edu.cn/         # HDU OJ 题解
├── qoj.ac/                 # QOJ 题解
├── ...                     # 其他平台题解
├── 2025icpc1/              # ICPC 2025 网络赛 1
├── 2025icpc2/              # ICPC 2025 网络赛 2
├── icpc2022hangzhou/       # ICPC 2022 Hangzhou
├── ccpc/                   # CCPC 题解
├── Daily_CF_Problems/      # 每日 CF 题目
├── jiangly/                # jiangly 模板参考
└── play/                   # 练习 / 实验代码
```

---

*主要使用语言：C++ | Main language: C++*
