// date: 2024-05-24 16:46:42
// tag: 位运算，线段树，字符串

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e5 + 10)
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

vector<int> a(N + 1), b(N + 1);
vector<pair<int, int>> d(N << 2);

pair<int, int> merge(const pair<int, int> &x, const pair<int, int> &y) {
  return {x.first | y.first, x.second | y.second};
}

void build(int l, int r, int p) {
  if (l == r) {
    d[p] = {a[l], b[l]};
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  d[p] = merge(d[lc], d[rc]);
}

pair<int, int> query(int l, int r, int s, int t, int p) {
  if (s > r || t < l) return {};
  if (l <= s && t <= r) return d[p];
  int mid = (s + t) / 2;
  return merge(query(l, r, s, mid, lc), query(l, r, mid + 1, t, rc));
}

void modify(int x, int s, int t, int p, const pair<int, int> &c) {
  if (x == s && x == t) {
    d[p] = c;
    return;
  }
  int mid = (s + t) / 2;
  if (x <= mid) modify(x, s, mid, lc, c);
  else modify(x, mid + 1, t, rc, c);
  d[p] = merge(d[lc], d[rc]);
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m, q;
  cin >> n >> m >> q;
  vector<string> str(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> str[i];
    for (int j = 0; j < n; j++) {
      if (str[i][j] == '0') a[i] ^= 1 << j;
      else if (str[i][j] == '1') b[i] ^= 1 << j;
    }
  }
  build(1, m, 1);
  int ans = 0;
  for (int _ = 1; _ <= q; _++) {
    int op;
    cin >> op;
    if (op == 0) {
      int l, r;
      cin >> l >> r;
      auto [x, y] = query(l, r, 1, m, 1);
      if ((x & y) == 0) {
        int t = (~x) & (~y), cnt = 0;
        for (int i = 0; i < n; i++) {
          cnt += t >> i & 1;
        }
        ans ^= 1 << cnt;
      }
    } else {
      int pos, va = 0, vb = 0;
      string s;
      cin >> pos >> s;
      for (int j = 0; j < n; j++) {
        if (s[j] == '0') va ^= 1 << j;
        else if (s[j] == '1') vb ^= 1 << j;
      }
      modify(pos, 1, m, 1, {va, vb});
    }
  }
  cout << ans << '\n';

  return 0;
}