#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> d(n + 1);
  auto add = [&](int x, int c) {
    for (int i = x; i <= n; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i - 1 - query(a[i]);
    add(a[i], 1);
  }
  for (int i = 1; i <= n; i++) {
    std::fill(d.begin(), d.end(), 0);
    int cur = 0;
    for (int j = i; j >= 1; j--) {
      cur += i - j - query(a[j])
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