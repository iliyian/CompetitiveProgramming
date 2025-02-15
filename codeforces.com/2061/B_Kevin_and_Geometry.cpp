#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  int mx = -1;
  for (auto &[k, v] : cnt) {
    if (v >= 2) {
      mx = std::max(mx, k);
    }
  }
  if (mx == -1) {
    std::cout << -1 << '\n';
    return;
  }
  cnt[mx] -= 2;
  int len = mx * 2;
  int prv = 0;
  std::vector<int> b;
  for (auto &[k, v] : cnt) {
    while (v--) {
      b.push_back(k);
    }
  }
  std::sort(b.begin(), b.end());
  for (int i = 1; i < b.size(); i++) {
    if (b[i] - b[i - 1] < len) {
      std::cout << b[i] << ' ' << b[i - 1] << ' ' << mx << ' ' << mx << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
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