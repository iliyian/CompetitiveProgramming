#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> vis(n + 1);
  std::queue<int> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (!vis[a[i]]) {
      std::cout << a[i] << ' ';
      vis[a[i]] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      std::cout << i << ' ';
    }
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}