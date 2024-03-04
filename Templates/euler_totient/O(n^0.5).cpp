// date: 2024-03-03 20:51:11
// tag: 求单个数的欧拉函数

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;

  auto phi = [](int x) {
    int ans = x;
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        ans = ans / i * (i - 1);
        while (x % i == 0) x /= i;
      }
    }
    if (x > 1) ans = ans / x * (x - 1);
    return ans;
  };

  int ans = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ans += i * phi(n / i);
      if (i * i != n) {
        ans += n / i * phi(i);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}