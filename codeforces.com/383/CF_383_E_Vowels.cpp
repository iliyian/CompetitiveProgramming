// date: 2025-07-30 12:12:27
// tag: sosdp std

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int mxS = 1 << 24;
  std::vector<int> f(mxS);
  for (int i = 0; i < n; i++) {
    char ch;
    int x = 0;
    for (int j = 0; j < 3; j++) {
      std::cin >> ch;
      x |= 1 << (ch - 'a');
    }
    f[x]++;
  }
  for (int i = 0; i < 24; i++) {
    for (int S = 0; S < mxS; S++) {
      if (S >> i & 1) {
        f[S] += f[S ^ (1 << i)];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < mxS; i++) { // 实际上这里是补集意义下的，不过枚举过程还是一样的，就无所谓了
    ans ^= (n - f[i]) * (n - f[i]);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}