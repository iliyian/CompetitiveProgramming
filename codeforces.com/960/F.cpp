// date: 2024-04-08 15:37:44
// tag: 线段树贪心

#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

int cnt = 0, lc[N << 5], rc[N << 5], rt[N << 5], mx[N << 5];

void pushup(int p) {
  mx[p] = max(mx[lc[p]], mx[rc[p]]);
}

void modify(int x, int c, int l, int r, int &p) {
  if (!p) p = ++cnt;
  if (l == r) {
    mx[p] = c;
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid) modify(x, c, l, mid, lc[p]);
  else modify(x, c, mid + 1, r, rc[p]);
  pushup(p);
}

int querymax(int l, int r, int s, int t, int &p) {
  if (l > r || !p) return 0;
  if (l <= s && t <= r) return mx[p];
  int mid = (s + t) / 2, ans = INT_MIN;
  if (l <= mid) ans = max(ans, querymax(l, r, s, mid, lc[p]));
  if (r > mid) ans = max(ans, querymax(l, r, mid + 1, t, rc[p]));
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    int v = querymax(1, w + 1, 1, N, rt[x]);
    v++;
    ans = max(ans, v);
    modify(w + 2, v, 1, N, rt[y]);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  solve();

  return 0;
}