// date: 2024/01/26 15:46:02
// tag: 倍增与贪心，断环，倍增的数值取得与限制条件

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int l, r, idx;
  bool operator < (const Node &b) {
    if (l != b.l) return l < b.l;
    return r > b.r;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Node> a(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r, a[i].idx = i;
    if (a[i].l > a[i].r) a[i].r += m;
    a[i + n].l = a[i].l + m;
    a[i + n].r = a[i].r + m;
  }
  sort(a.begin(), a.end());

  vector<vector<int>> f(n * 2 + 1, vector<int>(21));
  for (int i = 1, p = 1; i <= n * 2; i++) {
    while (p <= n * 2 && a[p].l <= a[i].r)
      p++;
    f[i][0] = p - 1;
  }
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= n * 2; j++)
      f[j][i] = f[f[j][i - 1]][i - 1];
  }
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    int k = i, lmt = a[i].l + m, sum = 0;
    for (int j = 20; j >= 0; j--) {
      if (f[k][j] && a[f[k][j]].r < lmt) {
        sum += (1 << j);
        k = f[k][j];
      }
    }
    ans[a[i].idx] = sum;
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] + 2 << ' ';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}