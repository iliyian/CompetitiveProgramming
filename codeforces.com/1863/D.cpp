// date: 2024/01/31 14:10:57
// tag: 构造算法，要分清影响或涉及限制条件与否的因素，
// 即本题中与循环方向垂直的多米诺是唯一影响的

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  vector<vector<int>> c(n, vector<int>(m));
  vector<int> rw(n), rb(n), cw(m), cb(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    int cnt = 0, col = 2;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'U') {
        cnt++;
        c[i][j] = col;
        col ^= 1;
        c[i + 1][j] = col;
      }
    }
    if (cnt & 1) {
      cout << "-1\n";
      return;
    }
  }
  for (int j = 0; j < m; j++) {
    int cnt = 0, col = 2;
    for (int i = 0; i < n; i++) {
      if (a[i][j] == 'L') {
        cnt++;
        c[i][j] = col;
        col ^= 1;
        c[i][j + 1] = col;
      }
    }
    if (cnt & 1) {
      cout << "-1\n";
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << (c[i][j] ? (c[i][j] == 2 ? 'B' : 'W') : '.');
    }
    cout << '\n';
  }

}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}