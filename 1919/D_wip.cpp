#include <bits/stdc++.h>
#define N 200005
using namespace std;

int l[N], r[N];
bitset<N> vis;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 2);
  int u = -1, cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      u = i;
      cnt++;
    }
    l[i] = i - 1, r[i] = i + 1;
  }
  if (cnt != 1) {
    cout << "NO\n";
    return;
  }
  queue<int> q;
  q.push(u);
  vis[u] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    int lc = l[u], rc = r[u];
    r[l[u]] = r[u], l[r[u]] = l[u];
    bool f = false;
    if (!vis[lc] && a[lc] == a[u] + 1)
      q.push(lc), f = true, vis[lc] = true;
    if (!vis[rc] && a[rc] == a[u] + 1)
      q.push(rc), f = true, vis[rc] = true;
    if (!f) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}