#include <bits/stdc++.h>
#define int long long

bool isprime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      int x = std::lcm(a[i], a[j]);
      bool f = false;
      for (int k = 2; k * k <= x; k++) {
        if (x % k == 0) {
          if (isprime(k) && isprime(x / k)) {
            f = true;
          }
          break;
        }
      }
      if (f) {
        ans++;
      }
    }
    std::cout << ans << '\n';
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