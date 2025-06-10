#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n * 2 + 1);
  int res = 0;
  for (int i = 1; i <= n * 2; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n * 2; i++) {
    if (i >= n) {
      res += a[i];
    } else {
      res -= a[i];
    }
  }
  std::cout << a[n * 2] << ' ' << res << ' ';
  for (int i = n * 2 - 1; i >= n + 1; i--) {
    std::cout << a[i] << ' ' << a[i - n] << ' ';
  }
  std::cout << a[n] << ' ';
  std::cout << '\n';
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