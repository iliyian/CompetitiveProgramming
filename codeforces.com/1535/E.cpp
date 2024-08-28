// date: 2024-08-20 17:48:18
// tag: 树上倍增，二分，贪心，模拟

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int q, a0, c0;
  std::cin >> q >> a0 >> c0;
  std::vector<std::array<int, 21>> pa(q + 1);
  std::vector<int> a(q + 1), c(q + 1), dep(q + 1);
  a[0] = a0, c[0] = c0;
  dep[0] = 1;
  auto get = [&](int d, int u) {
    for (int i = 20; i >= 0; i--) {
      if (dep[u] - (1 << i) >= d) {
        u = pa[u][i];
      }
    }
    return u;
  };
  for (int i = 1; i <= q; i++) {
    int op, x, y, z;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x >> a[i] >> c[i];
      pa[i][0] = x;
      dep[i] = dep[x] + 1;
      for (int j = 1; j <= 20; j++) {
        pa[i][j] = pa[pa[i][j - 1]][j - 1];
      }
    } else {
      std::cin >> x >> y;
      int l = 1, r = dep[x], ans = x;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (a[get(mid, x)]) r = mid - 1, ans = get(mid, x);
        else l = mid + 1;
      }
      int ansa = 0, ansc = 0;
      while (a[ans]) {
        int cnt = std::min(y, a[ans]);
        a[ans] -= cnt;
        y -= cnt;
        ansa += cnt;
        ansc += cnt * c[ans];
        if (ans == x || !y) break;
        ans = get(dep[ans] + 1, x);
      }
      std::cout << ansa << ' ' << ansc << std::endl;
    }
  }

  return 0;
}