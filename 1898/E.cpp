// date: 2024/02/26 12:36:59
// tag: 带条件的贪心，一遍过

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  vector<queue<int>> q(26);
  for (int i = 0; i < n; i++) {
    q[s[i] - 'a'].push(i);
  }
  for (int i = 0; i < m; i++) {
    int c = t[i] - 'a';
    if (q[c].empty()) {
      cout << "NO\n";
      return;
    }
    int p = q[c].front(); q[c].pop();
    for (int j = 0; j < c; j++) {
      while (!q[j].empty() && q[j].front() < p) {
        q[j].pop();
      }
    }
  }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}