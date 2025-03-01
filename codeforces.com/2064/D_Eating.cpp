// date: 2025-02-26 21:27:02
// tag: 位运算中按位从大到小贪心是不可或缺的一环

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), b(n + 1);
  std::vector<std::vector<int>> nxt(n + 1, std::vector<int>(31));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    b[i] = b[i - 1] ^ a[i];
    int j = 30;
    while (a[i] >> j & 1 ^ 1) {
      nxt[i][j] = nxt[i - 1][j];
      j--;
    }
    while (j >= 0) {
      nxt[i][j] = i;
      j--;
    }
  }
  while (q--) {
    int x;
    std::cin >> x;
    int i = 62;
    while (x >> i & 1 ^ 1) i--;
    int c = n;
    while (1) {
      if (!c || a[c] > x) break;
      x ^= a[c];
      if (!x) {
        c--;
        break;
      } 
      // std::cerr << x << ' ' << c << '\n';
      i = 62;
      while (x >> i & 1 ^ 1) i--;
      // std::cerr << i << ' ' << nxt[c - 1][i] << '\n';
      x ^= b[c - 1] ^ b[nxt[c - 1][i]];
      c = nxt[c - 1][i];
    }
    std::cout << n - c << ' ';
  }
  std::cout << '\n';
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