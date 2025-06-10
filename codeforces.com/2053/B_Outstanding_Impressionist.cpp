#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> l(n + 1), r(n + 1);
  std::vector<int> vis(n * 2 + 2), s(n * 2 + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i];
    if (l[i] == r[i]) {
      vis[l[i]] = 1;
      s[l[i]]++;
    }
  }
  for (int i = 1; i <= n * 2; i++) {
    vis[i] += vis[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    if (l[i] == r[i]) {
      if (s[l[i]] > 1) {
        std::cout << 0;
      } else {
        std::cout << 1;
      }
    } else {
      if (vis[r[i]] - vis[l[i] - 1] == r[i] - l[i] + 1) {
        std::cout << 0;
      } else {
        std::cout << 1;
      }
    }
  }
  std::cout << '\n';
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