// date: 2024-08-18 12:14:33
// tag: 差分维护的区间加，贪心，二分

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n, m, w;
  std::cin >> n >> m >> w;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  auto check = [&](int mid) {
    int cnt = 0;
    std::vector<int> f(n + w + 2);
    for (int i = 1; i <= n; i++) {
      f[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= n; i++) {
      f[i] += f[i - 1];
      if (f[i] < mid) {
        int d = mid - f[i];
        f[i] += d;
        f[i + w] -= d;
        cnt += d;
      }
    }
    return cnt <= m;
  };

  int l = 0, r = INT_MAX, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      l = mid + 1, ans = mid;
    } else  {
      r = mid - 1;
    }
  }
  std::cout << ans << '\n';

  return 0;
}