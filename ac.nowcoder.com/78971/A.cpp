#include <bits/stdc++.h>
// #define int long long
#define N 100005
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

int a[N], sm[31][N << 2];

void pushup(int p, int pos) {
  sm[pos][p] = sm[pos][lc] + sm[pos][rc];
}

void build(int l, int r, int p, int pos) {
  if (l == r) {
    sm[pos][p] = a[l] >> pos & 1;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc, pos);
  build(mid + 1, r, rc, pos);
  pushup(p, pos);
}

int querysum(int l, int r, int s, int t, int p, int pos) {
  if (l <= s && t <= r) return sm[pos][p];
  int mid = (s + t) / 2, ans = 0;
  if (l <= mid) ans += querysum(l, r, s, mid, lc, pos);
  if (r > mid) ans += querysum(l, r, mid + 1, t, rc, pos);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 31; i++) {
    build(1, n, 1, i);
  }
  for (int t = 0; t < k; t++) {
    int l, r, x;
    cin >> l >> r >> x;
    if (!x) {
      cout << r - l + 1 << '\n';
      continue;
    }
    int po;
    for (po = 30; po >= 0; po--) {
      if (x >> po & 1) {
        break;
      }
    }
    cout << (r - l + 1 - querysum(l, r, 1, n, 1, po)) << '\n';
  }

  return 0;
}