#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

// 全局变量存储输入和计算结果
ll p, q, k;
vector<pair<ll, int>> allowed_factors; // 允许的质因数及其指数限制
ll total_terminating_count = 0;

// 深度优先搜索，计算满足条件的 i 的数量
void dfs_count(int factor_idx, ll current_product) {
    // 越界检查
    if (current_product > q) {
        return;
    }
    
    // base case: 已经考虑完所有类型的质因数
    // current_product 本身就是一个合法的 i
    if (factor_idx == allowed_factors.size()) {
        total_terminating_count++;
        return;
    }

    // 不使用当前质因数，直接考虑下一个
    dfs_count(factor_idx + 1, current_product);

    ll prime = allowed_factors[factor_idx].first;
    int max_exponent = allowed_factors[factor_idx].second;
    
    ll temp_product = current_product;
    for (int i = 1; i <= max_exponent; ++i) {
        // 检查乘法是否会溢出或超过 q
        if (q / prime < temp_product) {
            break;
        }
        temp_product *= prime;
        dfs_count(factor_idx + 1, temp_product);
    }
}

// 另一个更简洁的DFS实现方式
void dfs_count_v2(int factor_idx, ll current_product) {
    if (factor_idx == allowed_factors.size()) {
        if (current_product > 0) { // 排除初始调用 dfs(0, 0) 的情况，如果这样设计
             total_terminating_count++;
        }
        return;
    }

    ll prime = allowed_factors[factor_idx].first;
    int max_exponent = allowed_factors[factor_idx].second;

    ll temp_product = current_product;
    for (int i = 0; i <= max_exponent; ++i) {
        if (temp_product > q) {
            break;
        }
        dfs_count_v2(factor_idx + 1, temp_product);
        
        if (q / prime < temp_product) { // 为下一次循环准备
            break;
        }
        temp_product *= prime;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> p >> q >> k;

    // 1. 找出 k 的所有质因数
    map<ll, bool> k_primes_map;
    ll temp_k = k;
    for (ll i = 2; i * i <= temp_k; ++i) {
        if (temp_k % i == 0) {
            k_primes_map[i] = true;
            while (temp_k % i == 0) {
                temp_k /= i;
            }
        }
    }
    if (temp_k > 1) {
        k_primes_map[temp_k] = true;
    }

    // 2. 计算 p_bad (p中与k互质的部分)
    ll p_bad = p;
    for (auto const& [prime, val] : k_primes_map) {
        while (p_bad > 0 && p_bad % prime == 0) {
            p_bad /= prime;
        }
    }

    // 3. 分解 p_bad，并与 k 的质因数合并
    map<ll, int> factors_map;
    
    // 加入 k 的质因数，指数限制设为 60 (2^60 > 10^18，足够大)
    for (auto const& [prime, val] : k_primes_map) {
        factors_map[prime] = 60;
    }

    // 分解 p_bad 并加入/更新 map
    ll temp_p_bad = p_bad;
    for (ll i = 2; i * i <= temp_p_bad; ++i) {
        if (temp_p_bad % i == 0) {
            int count = 0;
            while (temp_p_bad % i == 0) {
                temp_p_bad /= i;
                count++;
            }
            // p_bad 的质因数与 k 的质因数不相交
            factors_map[i] = count;
        }
    }
    if (temp_p_bad > 1) {
        factors_map[temp_p_bad] = 1;
    }

    // 将 map 转换为 vector 以便 DFS
    for (auto const& [prime, exponent] : factors_map) {
        allowed_factors.push_back({prime, exponent});
    }

    // 4. DFS 计数
    // 我们从1开始构建，所以初始 product 是 1
    dfs_count_v2(0, 1);
    
    // 5. 计算最终结果
    // dfs_count_v2(0, 1) 会计算所有满足条件的 i (包括1)
    // 所以总数是 total_terminating_count
    cout << q - total_terminating_count << endl;

    return 0;
}