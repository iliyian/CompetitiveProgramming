// date: 2024-04-16 20:58:22
// tag: 构造，树

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int s;
  vector<int> pa(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == i) s = i;
    else pa[i] = x;
  }

  vector<int> dis(n + 1, -1), p(n + 1);
  dis[s] = dis[0] = 0;
  bool f = true;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  if (p[1] != s) {
    f = false;
  }
  for (int i = 2; i <= n; i++) {
    if (dis[pa[p[i]]] == -1) {
      f = false;
    } else {
      dis[p[i]] = i - 1;
    }
  }
  if (!f) {
    cout << -1 << '\n';
    return;
  }
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    ans[i] = dis[i] - dis[pa[i]];
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
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