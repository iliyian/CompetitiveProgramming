// date: 2024-10-12 18:35:33
// tag: 构造，欧拉回路

#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("C.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  std::vector<std::array<int, 3>> c;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
    c.push_back({a[i], i, 0});
    c.push_back({b[i], i, 1});
  }
  std::sort(c.begin(), c.end());
  int sum = 0;
  std::array<int, 2> cnt;
  std::vector<std::array<int, 2>> vis(n + 1);
  bool f = false;
  for (int i = 0; i < n; i++) {
    sum += c[i][0];
    cnt[c[i][2]]++;
    vis[c[i][1]][c[i][2]] = true;
    if (vis[c[i][1]][0] && vis[c[i][1]][1]) {
      f = true;
    }
  }
  if (cnt[0] == n || cnt[1] == n || f) {
    std::cout << sum << '\n';
    return 0;
  }

  auto y = c[n - 1], z = c[n];
  sum -= y[0], sum += z[0];
  cnt[y[2]]--, cnt[z[2]]++;
  f = false;
  if (y[1] != z[1]) {
    f = true;
  }
  if (cnt[0] == n || cnt[1] == n || f) {
    std::cout << sum << '\n';
    return 0;
  }
  std::cout << std::min(sum + c[n + 1][0] - c[n][0], sum + c[n - 1][0] - c[n - 2][0]) << '\n';

  return 0;
}