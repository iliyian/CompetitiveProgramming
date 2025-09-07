#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> v(m);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    v[i % m].push_back(a[i]);
  }
  int mxans = 0, mnans = 0;
  for (auto &vec : v) {
    std::sort(vec.begin(), vec.end());
    int sum = std::accumulate(vec.begin(), vec.end(), 0ll);
    int mx = LLONG_MIN / 3, mn = LLONG_MAX / 3;
    int cnt = 0, tot = 0;
    std::set<int> s;
    for (int i = vec.size() - 1; i >= 0; i--) {
      if (i != vec.size() - 1) {
        if (vec[i] != vec[i + 1]) {
          tot += cnt;
          cnt = 0;
        }
      }
      int cur = sum + (k - 1 - vec[i]) * vec.size() - k * tot;
      mx = std::max(mx, cur);
      cnt++;
    }
    cnt = tot = 0;
    for (int i = 0; i < vec.size(); i++) {
      if (i) {
        if (vec[i] != vec[i - 1]) {
          tot += cnt;
          cnt = 0;
        }
      }
      int cur = sum - vec[i] * vec.size() + k * tot;
      cnt++;
      mn = std::min(mn, cur);
    }
    mxans += mx, mnans += mn;
  }
  std::cout << mxans << ' ' << mnans << '\n';
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