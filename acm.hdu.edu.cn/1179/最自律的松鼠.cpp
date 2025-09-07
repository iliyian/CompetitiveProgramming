#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, w;
  std::cin >> n >> w;
  std::vector<int> s(n + 10);
  int tot = 2, sum = w;
  s[2] = w;
  std::vector<int> val(n + 10), pa(n + 10), dep(n + 10);
  pa[2] = 2, pa[1] = 1;
  int l = 1, r = 2, top = 2;
  for (int i = 1; i <= n; i++) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int w;
      std::cin >> w;
      int u = ++tot;
      s[u] = s[top] + w;
      top = u;
      pa[u] = u;
      sum += w;
      r = u;
    } else if (op == 2) {
      int x, w;
      std::cin >> x >> w;
      int u = ++tot;
      pa[u] = pa[x];
      dep[u] = dep[x] + w;
      val[pa[x]] = std::max(val[pa[x]], dep[u]);
      if (val[pa[x]] == s[pa[x]]) {
        l = std::max(l, pa[x]);
      }
      if (val[pa[x]] == sum - s[pa[x]]) {
        r = std::min(r, pa[x]);
      }
    } else {
      std::cout << s[r] - s[l] << '\n';
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