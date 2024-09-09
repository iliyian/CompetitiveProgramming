// date: 2024-09-02 22:59:13
// tag: gcd系列操作，贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  int d = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    d = std::gcd(d, a[i]);
  } // 0d, 1d, 2d, (n-1)d
  if (n == 1) {
    std::cout << (k > d ? k : k - 1) << '\n';
    return;
  }
  if (d == 1) {
    std::cout << n + k - 1 << '\n';
    return;
  }
  int sum = (n - 1) * (d - 1);
  if (k > sum) {
    k -= sum;
    int ans = (n - 1) * d + k;
    std::cout << ans << '\n';
  } else {
    // [1,d-1]
    int s = (k + d - 2) / (d - 1) - 1;
    std::cout << s * d + k - s * (d - 1) << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}