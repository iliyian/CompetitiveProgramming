// date: 2024-08-03 21:34:29
// tag: 区间统计

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), x(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    x[i] = x[i - 1] ^ a[i];
  }
  int ans = 0;
  // int realans = 0;
  // for (int l = 1; l <= n; l++) {
  //   for (int r = l + 1; r <= n; r++) {
  //     realans += x[r] ^ x[l - 1];
  //   }
  // }
  // std::cout << realans << '\n';

  for (int i = 0; i <= 30; i++) {
    // int real = 0;
    // for (int l = 1; l <= n; l++) {
    //   for (int r = l + 1; r <= n; r++) {
    //     int cnt = 0;
    //     for (int j = l; j <= r; j++) {
    //       cnt ^= a[j] >> i & 1;
    //     }
    //     real += cnt;
    //   }
    // }

    std::vector<int> cnt(n + 1);
    std::vector<int> key;
    key.push_back(0);
    int res = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] >> i & 1)  {
        cnt[j] = j - key.back() - 1;
        if (key.size() > 2) {
          cnt[j] += cnt[key[key.size() - 2]] + 1;
        }
        key.push_back(j);
      } else {
        cnt[j] = cnt[j - 1] + (a[j - 1] >> i & 1);
      }
      res += cnt[j];
    }
    // assert(res == real);
    ans += res << i;
  }
  std::cout << ans << '\n';

  return 0;
}