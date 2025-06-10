#include <bits/stdc++.h>
#define int long long

void solve() {
  int P, n, k;
  std::cin >> P >> n >> k;
  std::vector<double> t0;
  std::vector<int> t1;
  for (int i = 1; i <= n; i++) {
    int t, x;
    std::cin >> t >> x;
    if (t) {
      t1.push_back(x);
    } else {
      t0.push_back(double(x) / 10);
    }
  }
  std::sort(t0.begin(), t0.end());
  for (int i = 1; i < t0.size(); i++) {
    t0[i] *= t0[i - 1];
  }
  std::sort(t1.begin(), t1.end(), std::greater<>());
  for (int i = 1; i < t1.size(); i++) {
    t1[i] += t1[i - 1];
  }
  if (t0.empty()) {
    std::cout << std::max<double>(0.0, P - t1[std::min<int>(t1.size(), k) - 1]) << '\n';
    return;
  }
  if (t1.empty()) {
    std::cout << std::max<double>(0.0, P * t0[std::min<int>(t0.size(), k) - 1]) << '\n';
    return;
  }
  if (t0.size() + t1.size() <= k) {
    std::cout << std::max(0.0, P * t0.back() - t1.back()) << '\n';
    return;
  }
  double ans = P - t1[std::min<int>(t1.size(), k) - 1];
  for (int i = 1; i <= std::min<int>(t0.size(), k); i++) {
    int j = std::min<int>(k - i, t1.size());
    ans = std::min(ans, P * t0[i - 1] - (j == 0 ? 0 : t1[j - 1]));
  }
  std::cout << std::max(0.0, ans) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  std::cout << std::fixed << std::setprecision(2);
  while (t--) {
    solve();
  }
  return 0;
}