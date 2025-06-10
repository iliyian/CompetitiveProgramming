// date: 2025-03-26 18:20:01
// tag: 扩展域并查集？这是真考验思维的一题，不过如果能想到再维护一层映射应该也是容易的吧

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> f(n + 1), g(n + 1), h(n + 1), pa(n + 1);
  for (int i = 1; i <= n; i++) {
    f[i] = g[i] = h[i] = pa[i] = i;
  }
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : self(self, pa[x]);};
  while (q--) {
    int op, a, b;
    std::cin >> op;
    if (op == 1) {
      std::cin >> a >> b;
      a = f[a], b = f[b];
      pa[b] = a;
    } else if (op == 2) {
      std::cin >> a >> b;
      h[a] = f[b];
    } else if (op == 3) {
      std::cin >> a >> b;
      std::swap(g[f[a]], g[f[b]]);
      std::swap(f[a], f[b]);
    } else {
      std::cin >> a;
      std::cout << g[find(find, h[a])] << '\n';
    }
  }
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