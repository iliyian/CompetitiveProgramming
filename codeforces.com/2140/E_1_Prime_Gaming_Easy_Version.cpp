#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  int c;
  std::cin >> c;
  std::vector<int> b(n);
  for (int i = 0; i < c; i++) {
    int x;
    std::cin >> x;
    x--;
    b[x] = 1;
  }
  if (m == 1) {
    std::cout << 1 << '\n';
    return;
  }
  // std::vector<std::vector<int>> f()
  // auto solve = [&](int s, bool flag, int n) {
  //   if (n == 1) {
  //     return s ? 2 : 1;
  //   }
  //   if (mem[s])
  // };
  std::vector<int> f(2);
  f[0] = 1;
  f[1] = 2;
  int s = 0;
  bool flag = n & 1 ^ 1;
  for (int i = 2; i <= n; i++) {
    std::vector<int> nf(1ll << i);
    for (int j = 0; j < (1ll << i); j++) {
      for (int k = 0; k < i; k++) {
        if (b[k]) {
          int t = j & ((1ll << k) - 1);
          t |= j >> (k + 1) << k;
          nf[j] |= f[t];
        }
      }
    }
    for (int j = 0; j < (1ll << i); j++) {
      if (nf[j] == 3) {
        if (flag) {
          nf[j] = 2;
        } else {
          nf[j] = 1;
        }
      }
    }
    f = nf;
    flag ^= 1;
  }
  std::cout << std::accumulate(f.begin(), f.end(), 0ll) << '\n';
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