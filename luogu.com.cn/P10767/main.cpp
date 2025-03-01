// date: 2024-08-01 11:39:32
// tag: 树形dp

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (x + y) / 2
// using namespace std;

constexpr int N = 2e6;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  
  std::vector<int> a(N + 1);
  for (int i = 1; i < (1 << n); i++) {
    std::cin >> a[i];
  }

  std::vector<int> l(N + 1), r(N + 1), L(n + 1, INT_MAX), R(n + 1, INT_MAX);
  auto dfs = [&](auto self, int p, int x, int y) -> void {
    if (y == x) return;
    int lv = std::__lg(y - x + 1);
    self(self, lc, x, mid);
    self(self, rc, mid + 1, y);

    if (a[p] == 1) {
      l[p] = l[lc] + l[rc] + 1;
      r[p] = std::min(r[lc], r[rc]);
    } else {
      l[p] = std::min(l[lc], l[rc]);
      r[p] = r[lc] + r[rc] + 1; // differ
    }
    L[lv] = std::min(L[lv], l[p]);
    R[lv] = std::min(R[lv], r[p]);
  };
  dfs(dfs, 1, 1, 1 << n);
  L[0] = R[0] = 0;

  while (m--) {
    int a, b;
    std::cin >> a >> b;
    b--;
    std::cout << (L[b] < a && (1 << n) + 1 - R[b] > a ? "Yes" : "No") << '\n';
  }

  return 0;
}