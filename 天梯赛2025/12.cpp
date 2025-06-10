#include <bits/stdc++.h>
#define int long long

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n, l, r;
  std::cin >> n >> l >> r;
  if (r < qpow(10, n - 1) || l >= qpow(10, n)) {
    std::cout << "No Solution";
    return;
  }
  if (l < qpow(10, n - 1)) l = qpow(10, n);
  if (r > qpow(10, n) - 1) r = qpow(10, n + 1) - 1;
  std::string sl = std::to_string(l);
  std::string sr = std::to_string(r);
  sl = '#' + sl;
  sr = '#' + sr;
  bool hasans = false;
  auto dfs = [&](auto self, int u, int prv, bool f, bool g) -> void {
    if (u == n + 1) {
      hasans = true;
      std::cout << prv << '\n';
      return;
    }
    for (int i = (f ? 0 : sl[u] - '0'); i <= (g ? 9 : sr[u] - '0'); i++) {
      if ((prv * 10 + i) % u == 0) {
        self(self, u + 1, prv * 10 + i, f | (i > sl[u] - '0'), g | (i < sr[u] - '0'));
      }
    }
  };
  dfs(dfs, 1, 0, 0, 0);
  if (!hasans) {
    std::cout << "No Solution";
    return;
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}