// date: 2024-08-06 10:17:27
// tag: 数位dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

long long n, k;

int check(int mid) {
  int ans = 0;
  int len = mid & 1 ^ 1;
  for (int i = 0; i <= __builtin_clzll(mid); i++, len++) {
    if ((mid << i) <= n) {
      ans += std::min((mid << i) + (1ll << len) - 1, n) - (mid << i) + 1;
    } else break;
  }
  return ans;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::cin >> n >> k;
  int l = 1, r = n / 2, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid * 2) >= k) l = mid + 1, ans = mid * 2;
    else r = mid - 1;
  }
  l = 1, r = (n + 1) / 2;
  int ans2 = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid * 2 - 1) >= k) l = mid + 1, ans2 = mid * 2 - 1;
    else r = mid - 1;
  }
  std::cout << (long long)std::max(ans, ans2) << '\n';

  return 0;
}