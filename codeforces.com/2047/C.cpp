#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].second;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].first > a[i].second) {
      ans += a[i].first;
      a[i].first = INT_MIN;
    } else {
      ans += a[i].second;
      a[i].second = INT_MIN;
    }
  }
  int mx = INT_MIN;
  for (int i = 1; i <= n; i++) {
    mx = std::max({mx, a[i].first, a[i].second});
  }
  std::cout << ans + mx << '\n';
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
