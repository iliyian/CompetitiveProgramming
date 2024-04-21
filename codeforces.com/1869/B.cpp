// date: 2023/12/16
// tag: 曼哈顿距离不存在两点间直线最短

#include <bits/stdc++.h>
#define N 200005
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int x[N], y[N];

void solve() {
  int n, k, a, b;
  cin >> n >> k >> a >> b;
  a--, b--;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  int min1 = inf, min2 = inf;
  for (int i = 0; i < k; i++) {
    min1 = min(min1, abs(x[i] - x[a]) + abs(y[i] - y[a]));
    min2 = min(min2, abs(x[i] - x[b]) + abs(y[i] - y[b]));
  }
  int ans = min(min1 + min2, abs(x[a] - x[b]) + abs(y[a] - y[b]));
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}