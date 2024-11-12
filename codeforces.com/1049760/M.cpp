#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  double ans = -1;
  for (int t = 0; t < 2; t++) {
    int mid = 1;
    while (a[mid + 1] < a[mid]) {
      mid++;
    }
    std::vector<std::pair<double, int>> lavg, ravg;
    double sum = a[mid];
    int cnt = 1;
    for (int i = mid - 1; i >= 1; i--) {
      cnt++;
      sum += a[i];
      lavg.push_back({sum / cnt, cnt});
    }
    cnt = 0, sum = 0;
    for (int i = mid + 1; i <= n; i++) {
      cnt++;
      sum += a[i];
      ravg.push_back({sum / cnt, cnt});
    }
    std::sort(lavg.begin(), lavg.end(), std::greater<>());
    double la = lavg.front().first;
    int lc = lavg.front().second;
    for (int i = 0; i < ravg.size(); i++) {
      double avg = ravg[i].first;
      int cn = ravg[i].second;
      ans = std::max(ans, 1.0 * (la * lc + avg * cn) / (lc + cn));
    }
    std::reverse(a.begin() + 1, a.end());
  }
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
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