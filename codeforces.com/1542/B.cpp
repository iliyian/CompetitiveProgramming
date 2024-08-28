// date: 2024-08-17 21:34:05
// tag: 位运算，数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  int k = n % b;
  if (b == 1) {
    std::cout << "Yes\n";
    return;
  }
  if (a == 1 && k != 1) {
    std::cout << "No\n";
    return;
  }
  for (int cur = 1; cur <= n; cur *= a) {
    assert(cur > 0);
    if (cur % b == k) {
      std::cout << "Yes\n";
      return;
    }
  }
  std::cout << "No\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}