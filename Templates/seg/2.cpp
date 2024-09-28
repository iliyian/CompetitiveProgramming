// date: 2024-09-21 21:43:24
// tag: 线段树，区间加乘

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int mod = 998244353;
constexpr int N = 2e5;

std::vector<int> a(N + 1);
std::vector<std::array<int, 2>> tag(N << 2);
std::vector<int> d(N << 2), len(N << 2);

int n, m;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}

int inv(int x) {
  return qpow(x, mod - 2);
}

void pull(int p) {
  d[p] = d[lc] + d[rc];
  d[p] %= mod;
}

void P(int p, int c, int typ) {
  if (typ == 1) { // add
    tag[p][0] = (tag[p][0] + c) % mod;
    d[p] = (d[p] + len[p] * c % mod) % mod;
  }
  if (typ == 2) { // mul
    tag[p][0] = tag[p][0] * c % mod;
    tag[p][1] = tag[p][1] * c % mod;
    d[p] = d[p] * c % mod;
  }
}

void push(int p) {
  if (tag[p][1] != 1) {
    P(lc, tag[p][1], 2);
    P(rc, tag[p][1], 2);
  }
  if (tag[p][0]) {
    P(lc, tag[p][0], 1);
    P(rc, tag[p][0], 1);
  }
  tag[p] = {0, 1};
}

void build(int s, int t, int p) {
  tag[p] = {0, 1};
  len[p] = t - s + 1;
  if (s == t) {
    d[p] = a[s];
    return;
  }
  build(s, mid, lc);
  build(mid + 1, t, rc);
  pull(p);
}

void add(int l, int r, int s, int t, int p, int c) {
  if (l > t || r < s) return;
  if (l <= s && t <= r) return P(p, c, 1);
  push(p);
  add(l, r, s, mid, lc, c);
  add(l, r, mid + 1, t, rc, c);
  pull(p);
}

void mul(int l, int r, int s, int t, int p, int c) {
  if (l > t || r < s) return;
  if (l <= s && t <= r) return P(p, c, 2);
  push(p);
  mul(l, r, s, mid, lc, c);
  mul(l, r, mid + 1, t, rc, c);
  pull(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) return d[p];
  push(p);
  return (query(l, r, s, mid, lc) + query(l, r, mid + 1, t, rc)) % mod;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("F.in", "r", stdin);

  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    int l, r, x;
    std::cin >> l >> r >> x;
    int len = r - l + 1;
    mul(l, r, 1, n, 1, (len - 1) * inv(len) % mod);
    add(l, r, 1, n, 1, inv(len) * x % mod);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << query(i, i, 1, n, 1) << ' ';
  }
  
  return 0;
}