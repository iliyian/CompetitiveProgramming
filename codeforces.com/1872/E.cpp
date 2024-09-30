#include <bits/stdc++.h>
#define N 100005
#define int long long
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

int a[N], d[N << 2][2];
string str;

void pushup(int p) {
  d[p][0] = d[lc][0] ^ d[rc][0];
  d[p][1] = d[lc][1] ^ d[rc][1];
}

void build(int l, int r, int p) {
  if (l == r) {
    d[p][0] = (str[l] == '0' ? a[l] : 0);
    d[p][1] = (str[l] == '1' ? a[l] : 0);
    return;
  }
  int mid = l + (r - l >> 1);
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

void modify(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) {
    swap(d[p][0], d[p][1]);
    return;
  }
  int mid = s + (t - s >> 1), ans = 0;
  if (l <= mid) modify(l, r, s, mid, lc);
  if (r > mid) modify(l, r, mid + 1, t, rc);
  pushup(p);
}

void solve() {
  int n, q;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  cin >> str;
  str = '#' + str;
  build(1, n, 1);
  cin >> q;
  for (int i = 0; i < q; i++) {
    int op;
    cin >> op;
    if (op == 2) {
      int x;
      cin >> x;
      cout << d[1][x] << ' ';
    } else {
      int l, r;
      cin >> l >> r;
      modify(l, r, 1, n, 1);
      // for (int j = l; j <= r; j++)
      //   modify(j, j, 1, n, 1);
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}