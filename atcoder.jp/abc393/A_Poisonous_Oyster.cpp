#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string a, b;
  std::cin >> a >> b;
  if (a == "fine" && b == "fine") {
    std::cout << 4;
  }
  if (a == "fine" && b == "sick") {
    std::cout << 3;
  }
  if (a == "sick" && b == "fine") {
    std::cout << 2;
  }
  if (a == "sick" && b == "sick") {
    std::cout << 1;
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