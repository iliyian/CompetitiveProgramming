#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n;
  std::cin >> n;

  int x = 0;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    x ^= a[i];
  }

  int ans = x;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n / i; j++) {
      ans = std::max(ans, (x ^ a[i]) ^ (a[i] * j));
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n / i; j++) {
      ans = std::max(ans, (x ^ a[i]) ^ (a[i] + j));
    }
  }

  std::cout << ans << '\n';

  return 0;
}