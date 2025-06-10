#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1), mp(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    mp[a[i]] = b[i];
    pos[b[i]] = i;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (mp[b[i]] != a[i]) {
      std::cout << -1 << '\n';
      return;
    }
    if (mp[b[i]] == b[i]) {
      cnt++;
    }
  }
  if (n % 2 == 0 && cnt || n % 2 == 1 && cnt != 1) {
    std::cout << -1 << '\n';
    return;
  }
  std::vector<std::pair<int, int>> ans;
  auto op = [&](int x, int y) {
    ans.push_back({x, y});
    pos[b[x]] = y;
    pos[b[y]] = x;
    std::swap(a[x], a[y]);
    std::swap(b[x], b[y]);
  };
  if (n % 2 == 1) {
    for (int i = 1; i <= n; i++) {
      if (a[i] == b[i]) {
        if (i != (n + 1) / 2) {
          op(i, (n + 1) / 2);
        }
        break;
      }
    }
  }
  for (int i = 1; i <= n / 2; i++) {
    if (a[i] != b[n - i + 1]) {
      op(n - i + 1, pos[a[i]]);
    }
  }
  std::cout << ans.size() << '\n';
  for (auto &[x, y] : ans) {
    std::cout << x << ' ' << y << '\n';
  }
  // std::cout << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << a[i] << ' ';
  // }
  // std::cerr << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << b[i] << ' ';
  // }
  // std::cerr << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}