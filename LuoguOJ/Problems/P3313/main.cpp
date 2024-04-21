#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Seg {
  int lc, rc, sm, mx;
};

void query(int l, int r, int p, bool isMx, auto func, int ini) {
  if (l <= s && t <= r) return mx[p];
  int mid = (p.lc + p.rc) / 2, ans = ini;
  if (l <= p.lc)
}

void hldquery(int x, int y, int c, auto func, int ini) {
  int ans = ini;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = func(ans, query())
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {

  }

  return 0;
}