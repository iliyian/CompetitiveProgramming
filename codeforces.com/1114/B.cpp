#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("B.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
  }
  std::stable_sort(a.begin() + 1, a.end(), std::greater<>());
  std::vector<int> pos(k + 1), idx(k * m + 1);
  int ans = 0;
  for (int i = 1; i <= k * m; i++) {
    idx[i] = a[i].second;
    ans += a[i].first;
  }
  std::sort(idx.begin() + 1, idx.end());
  for (int i = 1; i <= k - 1; i++) {
    pos[i] = idx[i * m];
  }
  std::cout << ans << '\n';
  for (int i = 1; i < k; i++) {
    std::cout << pos[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}