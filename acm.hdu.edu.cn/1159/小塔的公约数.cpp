#include <bits/stdc++.h>
// #define int long long

constexpr int N = 5e5;
// std::vector<int> fac[N + 1];
int a[N + 1], cnt[N + 1];

void solve() {
  int n;
  std::cin >> n;
  // int tot = 0;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = i; j <= n; j += i) {
      // fac[j].push_back(i);
  //     tot++;
  //   }
  // }
  // std::cerr << tot << '\n';
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i * 2; j <= n; j += i) {
      ans += cnt[j] * cnt[j - i];
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   if (!cnt[i]) continue;
  //   for (int j : fac[i]) {
  //     ans += cnt[i] * cnt[j * (i / j - 1)];
  //   }
    // for (int j = 1; j * j <= i; j++) {
    //   if (i % j == 0) {
    //     ans += cnt[i] * cnt[j * (i / j - 1)];
    //     if (j * j != i) {
    //       ans += cnt[i] * cnt[i / j * (j - 1)];
    //     }
    //   }
    // }
  // }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int i = 1; i <= N; i++) {
  //   for (int j = i; j <= N; j += i) {
  //     fac[j].push_back(i);
  //   }
  // }
  // int sum = 0;
  // for (int i = 1; i <= N; i++) {
  //   // mx = std::max<int>(mx, fac[i].size());
  //   sum += fac[i].size();
  // }
  // std::cerr << sum << '\n';

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}