#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 2), l(n + 2), r(n + 2);
  vector<bool> vis(n + 2);
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l[i] = i - 1, r[i] = i + 1;
    if (!a[i]) {
      q.push(i);
      vis[i] = true;
    }
  }
  if (q.size() != 1) {
    cout << -1 << '\n';
    return;
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    r[l[u]] = r[u], l[r[u]] = l[u];
    if (!vis[l[u]] && (a[l[l[u]]] == min(a[u], a[l[u]]) + 1 || a[r[l[u]]] == min(a[u], a[l[u]]) + 1)) {
      q.push(l[u]);
      vis[l[u]] = true;
    }
    if (!vis[r[u]] && (a[l[r[u]]] == min(a[u], a[r[u]]) + 1 || a[r[r[u]]] == min(a[u], a[r[u]]) + 1)) {
      q.push(r[u]);
      vis[r[u]] = true;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += !vis[i];
  }
  cout << (cnt == 1 ? "YES\n" : "NO\n");
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}