#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> v(n * 2 + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    auto b = a;
    // ans += i * i * a[i];
    for (int j = 1; j <= n; j++) {
      b[j] = (i == j ? 0 : a[j] > a[i] ? 1 : -1);
    }
    for (int j = 1; j <= n; j++) {
      b[j] += b[j - 1];
    }
    // std::cerr << i << ": ";
    // for (int j = 1; j <= n; j++) {
    //   std::cerr << b[j] << " ";
    // }
    // std::cerr << '\n';
    v[n] = 1;
    for (int j = 1; j <= n; j++) {
      if (j < i) {
        v[b[j] + n] += j + 1;
      } else {
        ans += v[b[j] + n] * a[i] * j;
      }
    }
    v[0] = 0;
    for (int j = 1; j < i; j++) {
      v[b[j] + n] = 0;
    }
    // std::cerr << ans << '\n';
  }
  std::cout << ans << '\n';
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