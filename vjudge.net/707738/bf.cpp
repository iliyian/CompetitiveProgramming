#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  n++;
  auto check = [&]() {
    if (n % m == 0) return true;
    std::string s = std::to_string(n);
    std::string t = std::to_string(m);
    return s.find(t) != s.npos;
  };
  while (1) {
    if (check()) break;
    n++;
  }
  std::cout << n << '\n';
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