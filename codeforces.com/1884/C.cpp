// 永远不要随意更改离散化后的数据，会很不幸，很不幸

#include <bits/stdc++.h>
#define N 100001
using namespace std;

int b[N << 2], maxd[N << 2], mind[N << 2];
int d[N << 2], dlen = 0;

void solve() {
  int n, m;
  cin >> n >> m;

  memset(mind, 0x3f, sizeof(mind));
  memset(maxd, -0x3f, sizeof(maxd));
  // memset(b, 0, sizeof(b));
  // memset(d, 0, sizeof(d));

  vector<pair<int, int>> v;
  dlen = 0;

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    v.push_back({l, r});
    d[++dlen] = l;
    d[++dlen] = r;
  }

  memset(b, 0, sizeof(b));
  sort(d + 1, d + dlen + 1);
  int len = unique(d + 1, d + dlen + 1) - d - 1;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].first == 1) continue;
    // 留罅隙
    int l = lower_bound(d + 1, d + len + 1, v[i].first) - d;
    int r = lower_bound(d + 1, d + len + 1, v[i].second) - d;
    b[l]++, b[r + 1]--;
  }
  for (int i = 1; i <= len; i++)
    b[i] += b[i - 1], ans = max(ans, b[i]);

  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; i++) {
    if (v[i].second == m) continue;
    int l = lower_bound(d + 1, d + len + 1, v[i].first) - d;
    int r = lower_bound(d + 1, d + len + 1, v[i].second) - d;
    b[l]++, b[r + 1]--;
  }
  for (int i = 1; i <= len; i++)
    b[i] += b[i - 1], ans = max(ans, b[i]);
  memset(b, 0, sizeof(b));


  cout << ans << '\n';
}

int main() {
  freopen("C.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}