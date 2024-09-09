#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int a, b;
  std::cin >> a >> b;
  if (a % 2 == 0 && a != 0 || a == 0 && b % 2 == 0) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}