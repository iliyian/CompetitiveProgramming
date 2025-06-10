// date: 2025-03-19 09:11:47
// tag: 神奇的adhoc题，首先要发现神奇的性质是每个数最多操作一次，序列操作最优问题，不妨首先考虑操作顺序和次数，或者反过来考虑哪些绝对不需要操作

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), mn(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  mn[n] = a[n];
  for (int i = n - 1; i >= 1; i--) {
    mn[i] = std::min(a[i], mn[i + 1]);
  }
  std::vector<int> f(n + 1);
  int mnn = LLONG_MAX;
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] > mn[i + 1]) {
      f[i] = 1;
      mnn = std::min(mnn, a[i] + 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!f[i] && a[i] > mnn) {
      f[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] += f[i];
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << ' ';
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