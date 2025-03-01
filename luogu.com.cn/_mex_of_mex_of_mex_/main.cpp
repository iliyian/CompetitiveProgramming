#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int N = 2e3 + 10;

int d[N << 2];

void update(int s, int t, int p, int x, int v, bool f) {
  if (s == t) {
    if (f) {
      d[p] = v;
    } else {
      d[p] = std::max(d[p], v);
    }
    return;
  }
  if (x <= mid) update(s, mid, lc, x, v, f);
  else update(mid + 1, t, rc, x, v, f);
  d[p] = std::min(d[lc], d[rc]);
}

int query(int s, int t, int p, int v) {
  if (s == t) return s;
  if (d[lc] < v) return query(s, mid, lc, v);
  return query(mid + 1, t, rc, v);
}

signed main(int argc, char **argv) {
  if (argc > 1) freopen(argv[1], "r", stdin);
  if (argc > 2) freopen(argv[2], "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> b(n + 1, std::vector<int>(n + 1));

  for (int r = 1; r <= n; r++) {
    update(0, n + 2, 1, a[r], r, true);
    for (int l = 1; l <= r; l++) {
      b[l][r] = query(0, n + 2, 1, l);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      update(0, n + 2, 1, b[i][j], 0, true);
    }
  }
  std::fill(d, d + (N << 2), 0);
#ifndef ONLINE_JUDGE
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j >= i) {
        std::cout << b[i][j] << ' ';
      } else {
        std::cout << "  ";
      }
    }
    std::cout << '\n';
  }
#endif
  std::vector<std::vector<int>> c(n + 1, std::vector<int>(n + 1));
  std::vector<int> able(n + 3);
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= j; i++) {
      update(0, n + 2, 1, b[i][j], i, false);
      if (i == j) {
        for (int l = 1; l <= j; l++) {
          c[l][j] = query(0, n + 2, 1, l);
          able[c[l][j]] = 1;
        }
      }
    }
  }
#ifndef ONLINE_JUDGE
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j >= i) {
        std::cout << c[i][j] << ' ';
      } else {
        std::cout << "  ";
      }
    }
    std::cout << '\n';
  }
#endif
  for (int i = 0; i <= n + 2; i++) {
    if (!able[i]) {
      std::cout << i << '\n';
      return 0;
    }
  }
  assert(false);
  return 0;
}