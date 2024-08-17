// date: 2024-08-09 14:46:29
// tag: 树形构造，距离一类

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int n, t, k;
  std::cin >> n >> t >> k;
  std::vector<int> a(t + 1);
  for (int i = 1; i <= t; i++) {
    std::cin >> a[i];
  }
  int mn = 0;
  for (int i = 2; i <= t; i++) {
    mn += std::min(a[i], a[i - 1]) - 1;
  }
  if (k > n - t || k < n - t - mn) {
    std::cout << -1 << '\n';
    return 0;
  }
  std::vector<int> pa(n + 1), fst(t + 1);
  fst[0] = 1;
  int id = 1;
  std::vector<std::vector<int>> lay(t + 1);
  for (int i = 1; i <= t; i++) {
    pa[++id] = fst[i - 1];
    fst[i] = id;
    for (int j = 2; j <= a[i]; j++) {
      pa[++id] = fst[i - 1];
      lay[i].push_back(id);
    }
  }
  int dep = 1, idx = 0;
  k = n - t - k;
  while (k--) {
    while (dep <= t - 1 && (idx >= lay[dep].size() || idx >= lay[dep + 1].size())) {
      dep++;
      idx = 0;
    }
    pa[lay[dep + 1][idx]] = lay[dep][idx];
    idx++;
  }
  std::cout << n << '\n';
  for (int i = 2; i <= n; i++) {
    std::cout << i << ' ' << pa[i] << '\n';
  }
  return 0;
}