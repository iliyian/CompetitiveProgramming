#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  int nlen = std::log10(n) + 1;
  for (int a = 1; a <= 10000; a++) {
    for (int b = 1; b <= std::min<int>(10000, n * a) && b < nlen * a; b++) {
      int x = n * a - b;
      int ylen = nlen * a - b;
      int blen = std::log10(b) + 1;
      if (ylen > blen + 1)
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}