#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int N = 5e5;

struct Seg {
  int llen0 = 0, llen1 = 0, rlen0 = 0, rlen1 = 0;
  int maxlen0 = 0, maxlen1 = 0;
  int len = 0;
};

std::vector<std::array<int, 2>> tag(N << 2);
std::vector<Seg> seg(N << 2);
std::vector<int> a(N + 1);

Seg merge(const Seg &x, const Seg &y) {
  if (!y.len) return x;
  if (!x.len) return y;
  auto s = Seg{
    x.llen0 == x.len ? x.llen0 + (x.len % 2 == 0 ? y.llen0 : y.llen1) : x.llen0,
    x.llen1 == x.len ? x.llen1 + (x.len % 2 == 0 ? y.llen1 : y.llen0) : x.llen1,
    y.rlen0 == y.len ? y.rlen0 + (y.len % 2 == 0 ? x.rlen0 : x.rlen1) : y.rlen0,
    y.rlen1 == y.len ? y.rlen1 + (y.len % 2 == 0 ? x.rlen1 : x.rlen0) : y.rlen1,
    std::max(x.maxlen0, y.maxlen0),
    std::max(x.maxlen1, y.maxlen1),
    x.len + y.len,
  };
  if (x.rlen0) {
    if (x.rlen0 % 2) {
      s.maxlen1 = std::max(s.maxlen1, x.rlen0 + y.llen1);
    } else {
      s.maxlen0 = std::max(s.maxlen0, x.rlen0 + y.llen1);
    }
  }
  if (x.rlen1) {
    if (x.rlen1 % 2) {
      s.maxlen0 = std::max(s.maxlen0, x.rlen1 + y.llen0);
    } else {
      s.maxlen1 = std::max(s.maxlen1, x.rlen1 + y.llen0);
    }
  }
  return s;
}

void exec(int s, int t, int p, int typ) {
  if (typ == 0) {
    tag[p] = {1, 0};
    seg[p] = {1, 0, 1, 0, 1, 0, seg[p].len};
  }
  if (typ == 1) {
    tag[p][1] ^= 1;
    seg[p] = {seg[p].llen1, seg[p].llen0, seg[p].rlen1, seg[p].rlen0, seg[p].maxlen1, seg[p].maxlen0, seg[p].len};
  }
}

void push(int s, int t, int p) {
  if (tag[p][0]) {
    exec(s, mid, lc, 0);
    exec(mid + 1, t, rc, 0);
  }
  if (tag[p][1]) {
    exec(s, mid, lc, 1);
    exec(mid + 1, t, rc, 1);
  }
  tag[p] = {0, 0};
}

void pull(int p) {
  seg[p] = merge(seg[lc], seg[rc]);
}

void build(int s, int t, int p) {
  seg[p].len = t - s + 1;
  if (s == t) {
    seg[p] = {!a[s], a[s], !a[s], a[s], !a[s], a[s], 1};
    return;
  }
  build(s, mid, lc);
  build(mid + 1, t, rc);
  pull(p);
}

// 只可能区间赋值为0
void reset(int l, int r, int s, int t, int p) {
  if (r < s || l > t)
    return;
  if (l <= s && t <= r) {
    exec(s, t, p, 0);
    return;
  }
  push(s, t, p);
  reset(l, r, s, mid, lc);
  reset(l, r, mid + 1, t, rc);
  pull(p);
}

void rev(int l, int r, int s, int t, int p) {
  if (r < s || l > t)
    return;
  if (l <= s && t <= r) {
    exec(s, t, p, 1);
    return;
  }
  push(s, t, p);
  rev(l, r, s, mid, lc);
  rev(l, r, mid + 1, t, rc);
  pull(p);
}

Seg query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return {};
  if (l <= s && t <= r) {
    return seg[p];
  }
  push(s, t, p);
  auto sl = query(l, r, s, mid, lc);
  auto rl = query(l, r, mid + 1, t, rc);
  return merge(sl, rl);
}

signed main(int argc, char **argv) {
  if (argc > 1) freopen(argv[1], "r", stdin);
  if (argc > 2) freopen(argv[2], "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  auto start = std::chrono::high_resolution_clock::now();

  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] &= 1;
  }
  build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    int op, l, r, x;
    std::cin >> op;
    if (op == 1 || op == 3) {
      std::cin >> l >> r >> x;
      if (x & 1) {
        rev(l, r, 1, n, 1);
      }
    } else if (op == 2) {
      std::cin >> l >> r >> x;
      if (x & 1 ^ 1) {
        reset(l, r, 1, n, 1);
      }
    } else {
      std::cin >> l >> r;
      int len = r - l + 1;
      auto s = query(l, r, 1, n, 1);
      std::cout << std::max(s.maxlen0, s.maxlen1) << '\n';
    }
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::cerr << std::chrono::duration<double, std::milli>(end - start) << '\n';

  return 0;
}