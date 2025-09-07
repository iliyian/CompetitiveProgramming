#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// 仍然使用 long long，好习惯！
#define int long long

// 这是一个辅助函数，专门用来合并两个DP表
// A代表用 a 行的解，B代表用 b 行的解，返回 a+b 行的解
std::vector<int> merge(const std::vector<int>& A, const std::vector<int>& B, int m) {
  std::vector<int> result(1 << m, 0);
  for (int mask = 0; mask < (1 << m); mask++) {
    // 遍历 mask 的所有子集 submask
    for (int submask = mask; ; submask = (submask - 1) & mask) {
      result[mask] = std::max(result[mask], A[submask] + B[mask ^ submask]);
      if (submask == 0) break; // 遍历子集的终止条件
    }
  }
  return result;
}

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  
  // 情况一：k >= m，这个逻辑不变
  if (k >= m) {
    std::vector<int> mx(m, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> a[i][j];
        mx[j] = std::max(mx[j], a[i][j]);
      }
    }
    std::cout << std::accumulate(mx.begin(), mx.end(), 0LL) << '\n';
    return;
  }

  // 如果 k < m，我们需要读入数据
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  // 如果 k=0，结果是0
  if (k == 0) {
    std::cout << 0 << '\n';
    return;
  }

  // --- 倍增DP开始 ---

  // 1. 预处理单行最优解 s (也就是 dp[1])
  std::vector<int> s(1 << m, 0);
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << m); mask++) {
      int current_sum = 0;
      for (int j = 0; j < m; j++) {
        if ((mask >> j) & 1) {
          current_sum += a[i][j];
        }
      }
      s[mask] = std::max(s[mask], current_sum);
    }
  }

  // 2. 预计算倍增表 dp_powers
  // dp_powers[i] 存储的是用 2^i 行的最优解
  std::vector<std::vector<int>> dp_powers;
  dp_powers.push_back(s); // dp_powers[0] 是 2^0=1 行的解

  for (int i = 0; (1 << (i + 1)) <= k; ++i) {
    // dp[2^(i+1)] = merge(dp[2^i], dp[2^i])
    dp_powers.push_back(merge(dp_powers.back(), dp_powers.back(), m));
  }

  // 3. 根据 k 的二进制位，合并最终答案
  std::vector<int> ans(1 << m, 0); // 最终答案，初始为0行，权值为0
  bool first_bit = true; // 用来标记是不是第一次合并

  for (int i = 0; i < dp_powers.size(); ++i) {
    if ((k >> i) & 1) { // 如果 k 的第 i 位是 1
      if (first_bit) {
        ans = dp_powers[i]; // 第一次直接赋值
        first_bit = false;
      } else {
        ans = merge(ans, dp_powers[i], m); // 后续进行合并
      }
    }
  }

  std::cout << ans[(1 << m) - 1] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // 如果题目要求多组测试，就解开这行注释
  std::cin >> t; 

  while (t--) {
    solve();
  }

  return 0;
}