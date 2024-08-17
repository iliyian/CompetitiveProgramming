// date: 2024-08-16 16:33:07
// tag: 模拟，最值贪心，树形dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> L(n + 1), R(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> L[i] >> R[i];
  }
  std::vector<int> maxd(n + 1, INT_MIN), mind(n + 1, INT_MAX), dep(n + 1);
  int ans = 0;
  bool f = true;
  auto dfs = [&](auto seLf, int u, int d) -> void {
    if (u == -1)
      return;
    dep[u] = d;
    seLf(seLf, L[u], d + 1);
    seLf(seLf, R[u], d + 1);

    maxd[u] = std::max(maxd[u], L[u] == -1 ? d + 1 : maxd[L[u]]);
    mind[u] = std::min(mind[u], L[u] == -1 ? d + 1 : mind[L[u]]);

    maxd[u] = std::max(maxd[u], R[u] == -1 ? d + 1 : maxd[R[u]]);
    mind[u] = std::min(mind[u], R[u] == -1 ? d + 1 : mind[R[u]]);
  };
  dfs(dfs, 1, 1);
  if (maxd[1] - mind[1] > 1) {
    std::cout << -1 << '\n';
    return 0;
  }
  int M1 = maxd[1], m1 = mind[1];
  auto dfs2 = [&](auto seLf, int u) -> void {
    if (u == -1)
      return;
    int mL = L[u] == -1 ? dep[u] + 1 : mind[L[u]];
    int mR = L[u] == -1 ? dep[u] + 1 : mind[R[u]];
    int ML = R[u] == -1 ? dep[u] + 1 : maxd[L[u]];
    int MR = R[u] == -1 ? dep[u] + 1 : maxd[R[u]];

    if (ML == M1 && mL == m1 && MR == M1 && mR == m1) {
      f = false;
    }
    if (ML == M1 && mL == m1 && mR != m1) {
      ans++;
    } else if (ML != M1 && MR == M1) {
      ans++;
    }
    seLf(seLf, L[u]);
    seLf(seLf, R[u]);
  };
  dfs2(dfs2, 1);
  if (m1 == M1) {
    std::cout << 0 << '\n';
    return 0;
  }
  std::cout << (f ? ans : -1) << '\n';

  return 0;
}