#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string a, b;
  std::cin >> a >> b;
  int i = 0;
  while (i < std::min(a.size(), b.size()) && a[i] == b[i]) i++;
  std::cout << (i ? i + 1 : 0) + a.size() - i + b.size() - i << '\n';
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