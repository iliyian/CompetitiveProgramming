#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

// int len = 5;
// std::vector<int> cur;
// std::map<int, int> cnt;

// void dfs(int u) {
//   if (u == len + 1) {
//     int ans = 0, t = 1;
//     for (int i = 0; i < cur.size(); i++) {
//       ans += cur[i] * t;
//       t = t * 2 % mod;
//     }
//     if (ans < (1 << len)) {
//       cnt[ans]++;
//     }
//     return;
//   }
//   for (int i = 0; i <= 20; i++) {
//     cur.push_back(i);
//     dfs(u + 1);
//     cur.pop_back();
//   }
// }

constexpr int N = 1e7 + 10;
int a[N + 1];

void solve() {
  int n;
  std::cin >> n;
  std::cout << a[n + 1] << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // std::fill(a + 1, a + N + 1, -1);
  a[1] = a[2] = 1;
  for (int i = 3; i <= N; i++) {
    if (i % 2 == 0) a[i] = a[i - 1];
    else a[i] = a[i - 1] + a[(i + 1) / 2];
    a[i] %= mod;
  }

  // dfs(1);
  // for (int i = 0; i < (1 << len); i++) {
  //   std::cout << cnt[i] << " ";
  // }
  // std::cout << '\n';
  // return 0;

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}