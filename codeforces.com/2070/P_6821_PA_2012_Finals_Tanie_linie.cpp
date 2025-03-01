#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  std::multiset<std::pair<int, int>> positive, negative;
  int sum = 0;
  std::vector<int> b = {0};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] == 0) continue;
    if (!b.empty() || b.back() < 0 && a[i] < 0 || b.back() > 0 && a[i] > 0) {
      b.back() += a[i];
    } else {
      b.push_back(a[i]);
    }
  }
  n = b.size();
  std::vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    l[i] = i - 1, r[i] = i + 1;
    if (a[i] > 0) positive.erase({b[i], i});
    else negative.erase({b[i], i});
  }
  while (positive.size() > k) {
    auto x = *positive.begin(), y = *negative.begin();
    if (x.first > -y.first) {
      auto l = 
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}