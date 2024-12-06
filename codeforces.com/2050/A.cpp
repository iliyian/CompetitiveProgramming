#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    a[i] = str.size();
  }
  // std::sort(a.begin() + 1, a.end());
  int i = 1, sum = 0;
  while (i <= n && a[i] + sum <= m) sum += a[i++];
  std::cout << i - 1 << '\n';
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