// date: 2024-07-24 09:01:30
// tag: 

#include <bits/stdc++.h>
#include <cmath>
#define int long long
// using namespace std;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  std::vector<int> c(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    if (a[i] == 1 && a[i - 1] > 1) {
      std::cout << -1 << '\n';
      return;
    }
    if (a[i] == a[i - 1] && c[i - 1] == 0) continue;
    c[i] = std::ceil(std::log(std::log(a[i - 1]) / std::log(a[i])) / std::log(2) + double(c[i - 1]));
    c[i] = std::max(0ll, c[i]);
    ans += c[i];
  }
  std::cout << ans << '\n';
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