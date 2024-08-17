#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, x, p;
  std::cin >> n >> x >> p;
  // f*(f+1)/2=n-x(mod n) n>=x f>0
  int t = n - x;
  for (int i = 1; i <= std::min(n * 3, p); i++) {
    int v = (x + i * (i + 1) / 2 % n) % n;
    if (v == 0) {
      std::cout << "Yes\n";
      return;
    }
  }
  std::cout << "No\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}