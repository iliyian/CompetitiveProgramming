#include <iostream>
#include <vector>
#include <algorithm>
#include <map> // 或者用数组，如果颜色值经过离散化或本身不大

#ifdef __GNUC__
#include <string.h> 
#else
#include <cstring> 
#endif

const int MAXN_NODES = 100005;
// 假设颜色值在离散化后或本身就在 0 到 MAXN_NODES-1 的范围内
const int MAX_COLOR_VAL = MAXN_NODES; 

std::vector<int> adj[MAXN_NODES];
int color[MAXN_NODES];
int subtree_sz[MAXN_NODES];
int heavy_child_node[MAXN_NODES];

int color_freq[MAX_COLOR_VAL];
int distinct_colors_count_current;
int max_distinct_colors_on_path;

// 更新颜色频率和当前不同颜色数
void update_freq(int node_color_val, int delta) {
    if (delta == 1) { // Add color
        if (color_freq[node_color_val] == 0) {
            distinct_colors_count_current++;
        }
        color_freq[node_color_val]++;
    } else { // Remove color (delta == -1)
        color_freq[node_color_val]--;
        if (color_freq[node_color_val] == 0) {
            distinct_colors_count_current--;
        }
    }
}

// DFS来计算子树大小和确定重儿子
void dfs_calc_size(int u, int p) {
    subtree_sz[u] = 1;
    heavy_child_node[u] = 0; // 0表示没有重儿子
    int max_c_sz = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_calc_size(v, u);
        subtree_sz[u] += subtree_sz[v];
        if (subtree_sz[v] > max_c_sz) {
            max_c_sz = subtree_sz[v];
            heavy_child_node[u] = v;
        }
    }
}

// 将子树 u 中的所有节点颜色按 delta (+1 或 -1) 更新到全局频率计数
// if for_querying is true, update global answer during additions
void process_subtree_for_sack(int u, int p, int delta, bool for_querying) {
    update_freq(color[u], delta);
    if (for_querying && delta == 1) {
        max_distinct_colors_on_path = std::max(max_distinct_colors_on_path, distinct_colors_count_current);
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        process_subtree_for_sack(v, u, delta, for_querying);
    }
}

// Sack算法主DFS
void dfs_sack_main(int u, int p, bool keep_color_data) {
    // 1. 处理轻儿子 (递归调用，然后清除它们的数据)
    for (int v : adj[u]) {
        if (v == p || v == heavy_child_node[u]) continue;
        dfs_sack_main(v, u, false); // false: 处理完后清除数据
    }

    // 2. 处理重儿子 (递归调用，并保留其数据)
    if (heavy_child_node[u] != 0) {
        dfs_sack_main(heavy_child_node[u], u, true); // true: 保留重儿子子树的数据
        // 此刻, color_freq 和 distinct_colors_count_current 反映了重儿子子树的颜色信息
    }

    // 3. 处理当前节点 u
    update_freq(color[u], 1); // 将 u 的颜色加入
    // 路径可能是 u 到其重儿子子树中的某个节点
    max_distinct_colors_on_path = std::max(max_distinct_colors_on_path, distinct_colors_count_current);

    // 4. 再次处理轻儿子: 将它们的颜色数据加入当前统计，并查询
    // 当前统计已包含 u 和其重儿子子树。加入轻儿子子树的节点可以构成经过 u 的路径。
    for (int v : adj[u]) {
        if (v == p || v == heavy_child_node[u]) continue;
        // 将轻儿子 v 的子树中所有节点加入，并在过程中更新答案
        process_subtree_for_sack(v, u, 1, true);
    }
    
    // 5. 清理: 如果 keep_color_data 为 false，则清除整个 u 子树的颜色数据
    if (!keep_color_data) {
        process_subtree_for_sack(u, p, -1, false); // false: 不在清理时更新答案
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 假设颜色是1到N。如果颜色范围更大或有0，需要调整MAX_COLOR_VAL和数组索引。
    // 如果颜色值本身很大，需要先进行离散化。
    // 这里假设节点是1-indexed，颜色也是1-indexed。
    for (int i = 1; i <= n; ++i) {
        std::cin >> color[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u_node, v_node;
        std::cin >> u_node >> v_node;
        adj[u_node].push_back(v_node);
        adj[v_node].push_back(u_node);
    }

    // 初始化全局变量
    max_distinct_colors_on_path = 0;
    distinct_colors_count_current = 0;
    // memset(color_freq, 0, sizeof(color_freq)); // 全局数组会自动初始化为0

    // 启动Sack算法 (假设根节点为1, 0为虚拟父节点)
    dfs_calc_size(1, 0); 
    dfs_sack_main(1, 0, false); // 对于根节点的调用，keep_color_data 通常为 false

    std::cout << max_distinct_colors_on_path << std::endl;

    return 0;
}