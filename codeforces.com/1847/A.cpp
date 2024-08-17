#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> vis(n + 1);
  int ans = 0;
  for (int i = 1; i <= k - 1; i++) {
    int mx = -1, pos = 0;
    for (int j = 1; j < n; j++) {
      if (!vis[j] && std::abs(a[j + 1] - a[j]) >= mx) {
        mx = std::abs(a[j + 1] - a[j]);
        pos = j;
      }
    }
    vis[pos] = true;
  }
  for (int i = 1; i < n; i++) {
    if (!vis[i]) {
      ans += std::abs(a[i + 1] - a[i]);
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}