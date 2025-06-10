#include <bits/stdc++.h>
#include <vector>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string str;
  std::cin >> str;
  std::vector<std::string> s(m + 1), t(m + 1);
  std::vector<int> a(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i] >> s[i] >> t[i];
  }
  std::vector<std::vector<int>> to(1 << n, std::vector<int>(m + 1));
  for (int S = (1 << n); S > 0; S--) {
    for (int i = 1; i <= m; i++) {
      
    }
  }
  std::vector<int> f(1 << n);
  for (int S = (1 << n); S > 0; S--) {
    for (int i = 1; i <= m; i++) {
      f[set(S, i)] = std::min(f[set(S, i)], f[S] + a[i]);
    }
  }
  std::cout << f[0] << '\n';
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