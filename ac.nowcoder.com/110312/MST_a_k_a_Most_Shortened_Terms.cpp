#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::string x, y, z;
  std::cin >> x >> y >> z;
  if (x.front() == 'M' && y.front() == 'S' && z.front() == 'T') {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
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