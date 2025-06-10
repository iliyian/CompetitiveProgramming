#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  // std::vector<int> pos1(n + 1), pos2(n + 1);
  std::vector<std::array<int, 2>> pos1(n + 1, {0, 0}), pos2(n + 1, {0, 0});
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i >= 3) {
      pos1[a[i - 2]][i & 1] = i - 2;
      pos2[b[i - 2]][i & 1] = i - 2;
    }
    if (a[i] == b[i]) {
      ans = std::max(ans, i);
    }
    if (a[i] == a[i - 1] || b[i] == b[i - 1]) {
      ans = std::max(ans, i - 1);
    }
    // if (pos1[a[i]][i & 1 ^ 1]) {
    //   ans = std::max(ans, pos1[a[i]][i & 1 ^ 1]);
    // }
    // if (pos2[b[i]][i & 1 ^ 1]) {
    //   ans = std::max(ans, pos2[b[i]][i & 1 ^ 1]);
    // }
    ans = std::max({ans, pos1[b[i]][0], pos1[b[i]][1]});
    ans = std::max({ans, pos2[a[i]][0], pos2[a[i]][1]});
    ans = std::max({ans, pos2[b[i]][0], pos2[b[i]][1]});
    ans = std::max({ans, pos1[a[i]][0], pos1[a[i]][1]});
  }
  std::cout << ans << '\n';
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