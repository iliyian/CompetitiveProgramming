#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  

  int real = 0;
  for (int i = 1; i <= n; i++) {
    int l = i;
    while (l <= n) {
      int r = std::upper_bound(a.begin() + l, a.end(), a[l - 1] + x) - a.begin();
      real += r - l;
      l = r + 1;
    }
  }
  std::cout << real << '\n';
}

signed main() {
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