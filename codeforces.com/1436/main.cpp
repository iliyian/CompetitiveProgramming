#include <bits/stdc++.h>
#define mid (s + t) / 2
// #define int long long

constexpr int N = 1e7;

int lc[N], rc[N], mn[N], rt[N];
int cnt = 0;

int update(int s, int t, int pre, int x, int v) {
  int p = ++cnt;
  lc[p] = lc[pre], rc[p] = rc[pre], mn[p] = mn[pre];
  if (s == t) {
    mn[p] = v;
    return p;
  }
  if (x <= mid) lc[p] = update(s, mid, lc[p], x, v);
  else rc[p] = update(mid + 1, t, rc[p], x, v);
  mn[p] = std::min(mn[lc[p]], mn[rc[p]]);
  return p;
}

int query(int s, int t, int p, int x) {
  if (s == t) return s;
  if (mn[lc[p]] < x) return query(s, mid, lc[p], x);
  return query(mid + 1, t, rc[p], x);
}

signed main() {
  freopen("main.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), lst(n + 1);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx = std::max(mx, a[i]);
  }
  std::vector<std::vector<std::pair<int, int>>> ask(n + 1);
  for (int i = 1; i <= n; i++) {
    if (lst[a[i]] + 1 <= i - 1) {
      ask[i - 1].push_back({lst[a[i]] + 1, a[i]}); 
    }
    lst[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (lst[a[i]] + 1 <= n) {
      ask[n].push_back({lst[a[i]] + 1, a[i]}); 
    }
  }
  ask[n].push_back({1, mx + 1});
  for (int i = 1; i <= n; i++) {
    rt[i] = update(1, n + 2, rt[i - 1], a[i], i);
  }
  std::vector<int> able(n + 6);
  for (int r = 1; r <= n; r++) {
    for (auto &[l, x] : ask[r]) {
      // std::cout << l << ' ' << r << ' ' << query(1, n, rt[r], l) << '\n';
      able[query(1, n + 2, rt[r], l)] = 1;
      // if (query(1, n + 2, rt[r], l) == x) {
      //   able[x] = 1;
      // }
    }
  }
  for (int i = 1; i <= n + 3; i++) {
    if (!able[i]) {
      std::cout << i << ' ';
      return 0;
    }
  }
  assert(false);
  return 0;
}