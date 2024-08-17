#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
// using namespace std;

struct Seg {
  int maxlen, llen, rlen, len;
};

Seg merge(const Seg &x, const Seg &y) {
  return {std::max({x.maxlen, y.maxlen, x.rlen + y.llen}),
    x.len == x.maxlen ? x.len + y.llen : x.llen,
    y.len == y.maxlen ? y.len + x.rlen : y.rlen,
    x.len + y.len
    };
};

constexpr int N = 1e6;

std::vector<Seg> d(N << 2);

void pushup(int p) {
  d[p] = merge(d[lc], d[rc]);
}

void modify(int x, int s, int t, int p, int c) {
  if (x == s && x == t) {
    d[p] = {c, c, c, d[p].len};
    return;
  }
  if (x <= mid) modify(x, s, mid, lc, c);
  else modify(x, mid + 1, t, rc, c);
  pushup(p);
}

int query(int s, int t, int p, int k) {
  if (t - s + 1 < k) return -1;
  if (d[lc].maxlen >= k) return query(s, mid, lc, k);
  if (d[lc].rlen + d[rc].llen >= k) return query(s, mid, lc, k - d[lc].rlen)
}

void solve() {
  int n;
  std::cin >> n;

  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    s.insert(x);
    modify(x, 1, N, 1, 1);
  }
  int q;
  std::cin >> q;
  while (q--) {
    char op;
    int x;
    std::cin >> op >> x;
    if (op == '-') {
      s.erase(x);
    } else if (op == '+') {
      s.insert(x);
    } else {

    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}