// date: 2024-04-23 16:17:06
// tag: 背包，bfs

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> mem(1001);

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> b(n + 1), v(n + 1), w(n + 1, INT_MAX);
  int sumw = 0;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (mem[b[i]]) {
      w[i] = mem[b[i]];
      sumw += w[i];
      continue;
    }
    queue<pair<int, int>> q;
    bitset<1001> vis;
    q.push({1, 0});
    vis[1] = true;
    while (!q.empty()) {
      auto [u, t] = q.front(); q.pop();
      if (u == b[i]) {
        w[i] = t;
        break;
      }
      for (int j = 1; j <= u; j++) {
        if (u + u / j <= b[i] && !vis[u + u / j]) {
          q.push({u + u / j, t + 1});
          vis[u + u / j] = true;
        }
      }
    }
    sumw += mem[b[i]] = w[i];
  }
  int sumv = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    sumv += v[i];
  }
  if (sumw <= k) {
    cout << sumv << '\n';
    return;
  }
  vector<int> dp(k + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = k; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  cout << dp[k] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}