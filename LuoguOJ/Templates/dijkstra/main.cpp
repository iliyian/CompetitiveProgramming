// date: 2024-02-28 15:42:12
// tag: 用本子推一遍数学原理或者公式似乎更好
// re#01: inv数组越界，可能H=1
// wa, 线性同余方程的a,b最好预处理成都是正数,但是有一处处理后忘记取模了

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

void solve() {
  int n, m, H;
  cin >> n >> m >> H;
  vector<int> l(n + 1), s(n + 1);
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y), adj[y].push_back(x);
  }
  auto exgcd = [](auto self, int a, int b, int &x, int &y) {
    if (b == 0) {
      x = 1, y = 0;
      return a;
    }
    int g = self(self, b, a % b, y, x);
    y -= a / b * x;
    return g;
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  vector<int> dis(n + 1, -1);
  q.push({0, 1});
  while (!q.empty()) {
    auto [d, x] = q.top(); q.pop();
    if (dis[x] != -1) continue;
    dis[x] = d;
    for (int y : adj[x]) {
      int curx = (l[x] + d % H * s[x]) % H;
      int cury = (l[y] + d % H * s[y]) % H;
      int a, b, diff = (curx - cury + H) % H, chg = (s[y] - s[x] + H) % H;
      int g = exgcd(exgcd, chg, H, a, b);
      if (diff % g) {
        continue;
      }
      diff /= g;
      a = a * diff % (H / g);
      a = (a + H / g) % (H / g);
      q.push({d + a + 1, y});
    }
  }
  cout << dis[n] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}