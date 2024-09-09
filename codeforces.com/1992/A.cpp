#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  std::array<int, 3> a;
  std::cin >> a[0] >> a[1] >> a[2];
  for (int i = 1; i <= 5; i++) {
    (*std::min_element(a.begin(), a.end()))++;
  }
  std::cout << a[0] * a[1] * a[2] << '\n';
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