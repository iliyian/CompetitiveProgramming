// date: 2024-09-24 20:55:50
// tag: 主席树，可持久化权值线段树上差分

#include <bits/stdc++.h>
#define int long long
#define mid (s + t) / 2
#define lc seg[p].ls
#define rc seg[p].rs

constexpr int mod = 1e9;
constexpr int N = 7.5e4;

struct Node {
  int x, y;
};

struct Seg {
  int ls, rs;
  int sumx, sumy;
  Seg operator + (const Seg &b) const {
    return {
      0, 0,
      sumx + b.sumx, sumy + b.sumy,
    };
  }
  Seg operator - (const Seg &b) const {
    return {
      0, 0,
      sumx - b.sumx, sumy - b.sumy,
    };
  }
};
// 一次操作logw=30个节点，1e5次操作，开64N
// 麻了，开500M得了
std::vector<Seg> seg(15000000);
std::vector<int> rt(N + 1);
int cnt = 0;

void build(int s, int t, int &p) {
  p = ++cnt;
  if (s == t) return;
  build(s, mid, lc);
  build(mid + 1, t, rc);
}

int update(int x, int s, int t, int pre, int k1, int k2) {
  int p = ++cnt;
  seg[p] = seg[pre];
  seg[p].sumx += k1, seg[p].sumy += k2;
  if (s == t) return p;
  if (x <= mid) lc = update(x, s, mid, lc, k1, k2);
  else rc = update(x, mid + 1, t, rc, k1, k2);
  return p;
}

Seg query(int x, int s, int t, int p) {
  if (x < s) return {};
  if (t <= x) return seg[p];
  return query(x, s, mid, lc) + query(x, mid + 1, t, rc);
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("G.in", "r", stdin);
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x1, x2, y1, a, b, y2;
    std::cin >> x1 >> x2 >> y1 >> a >> b >> y2;
    rt[i] = update(0, 0, mod, rt[i - 1], 0, y1);
    rt[i] = update(x1 + 1, 0, mod, rt[i], a, b - y1);
    rt[i] = update(x2 + 1, 0, mod, rt[i], -a, y2 - b);
  }
  int m, last = 0;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int l, r, x;
    std::cin >> l >> r >> x;
    x = (x + last) % mod;
    auto s = query(x, 0, mod, rt[r]) - query(x, 0, mod, rt[l - 1]);
    int ans = x * s.sumx + s.sumy;
    last = ans;
    std::cout << ans << '\n';
  }
  return 0;
}