#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int w;
  std::cin >> w;
  std::vector<int> c(w);
  for (int i = 0; i < w; i++) {
    std::cin >> c[i];
  }
  int q;
  std::cin >> q;
  while (q--) {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int S = 1; S < (1ll << w); S++) {
      int cnt = __builtin_popcountll(S), cur = 0;
      for (int i = 0; i < w; i++) {
        if (S >> i & 1) {
          cur += 
        }
      }
    }
  }
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