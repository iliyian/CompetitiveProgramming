// date: 2025-02-12 17:02:40
// tag: 有意思的三分线段树

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::string str;
  std::cin >> n >> q >> str;
  int N = pow(3, n);
  std::vector<int> a(N);
  for (int i = 0; i < N; i++) {
    a[i] = (str[i] == 'A' ? 1 : 0);
  }
  // for (int i = 0; i < N; i++) {
  //   std::cerr << a[i] << ' ';
  // }
  // std::cerr << '\n';
  std::vector<std::vector<int>> f(N, std::vector<int>(n + 1));
  auto dfs = [&](auto self, int l, int r, int len) -> int {
    if (r == l + 1) return f[l][len] = a[l];
    int t = (r - l) / 3;
    return f[l][len] = 
      (self(self, l, l + t, len - 1) 
      + self(self, l + t, l + t * 2, len - 1)
      + self(self, l + t * 2, l + t * 3, len - 1)
      >= 2);
  };
  dfs(dfs, 0, N, n);
  auto modify = [&](auto self, int l, int r, int x, int len) -> void {
    if (l == r - 1) {
      assert(len == 0);
      f[l][len] ^= 1;
      return;
    }
    int lmid = (l * 2 + r) / 3, rmid = (l + 2 * r) / 3;
    if (x < lmid) {
      self(self, l, lmid, x, len - 1);
    } else if (x < rmid) {
      self(self, lmid, rmid, x, len - 1);
    } else {
      self(self, rmid, r, x, len - 1);
    }
    f[l][len] = (f[l][len - 1] + f[lmid][len - 1] + f[rmid][len - 1] >= 2);
  };
  while (q--) {
    int x;
    std::cin >> x;
    x--;
    modify(modify, 0, N, x, n);
    std::cout << (f[0][n] ? 'A' : 'B') << '\n';
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