#include <bits/stdc++.h>

typedef long long int64;

const int N = 100000, M = 20;
const int64 INF = (1LL << 60) - 1;

int n, m, a[N + 9], g[(1 << M) + 9];

void Read() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    std::cin >> a[i];
  for (int i = 0; i < 1 << m; ++i)
    std::cin >> g[i];
}

int64 dp[N + 9];

void DP() {
  dp[0] = 0;
  std::vector<std::tuple<int64, int, int>> vec;
  vec.emplace_back(dp[0], (1 << m) - 1, 0);
  for (int i = 1; i <= n; ++i) {
    dp[i] = -INF;
    for (auto &[val, sand, sor] : vec) {
      sand &= a[i];
      sor |= a[i];
      dp[i] = std::max(dp[i], val + g[sor - sand]);
    }
    auto tmp = vec;
    vec.clear();
    for (int i = 0; i < (int)tmp.size(); ++i)
      if (vec.empty() || std::get<1>(vec.back()) != std::get<1>(tmp[i]) ||
          std::get<2>(vec.back()) != std::get<2>(tmp[i])) {
        vec.push_back(tmp[i]);
      } else {
        std::get<0>(vec.back()) =
            std::max(std::get<0>(vec.back()), std::get<0>(tmp[i]));
      }
    vec.emplace_back(dp[i], (1 << m) - 1, 0); 
  }
  std::cout << dp[n] << '\n';
}

void work() {
  Read();
  DP();
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int T = 1;
  std::cin >> T;
  for (; T--;)
    work();
  return 0;
}