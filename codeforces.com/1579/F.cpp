// date: 2024-04-12 12:37:33
// tag: bfs

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, d;
  cin >> n >> d;
  queue<int> q;
  vector<int> a(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!a[i]) {
      q.push(i);
    }
  }
  int ans = -1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ans = max(ans, c[u]);
    int nxt = (u + d) % n;
    if (!nxt) nxt = n;
    if (a[nxt]) {
      q.push(nxt);
      a[nxt] = 0;
      c[nxt] = c[u] + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}