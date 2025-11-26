#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  auto t = s;
  std::ranges::sort(t);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += s[i] != t[i];
  }
  std::cout << cnt / 2 << '\n';
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