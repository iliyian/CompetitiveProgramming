#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::string str;
  std::cin >> str;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = str[i - 1] == '1';
    a[i] += a[i - 1];
  }
  int ans = 0;
  for (int i = 1; i + m - 1 <= n; i++) {
    if (a[i + m - 1] == a[i - 1]) {
      ans++;
      i = i + m - 1 + k - 1;
    }
  }
  std::cout << ans << '\n';
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