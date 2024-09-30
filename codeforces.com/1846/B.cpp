#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a[3];
  for (int i = 0; i < 3; i++)
    cin >> a[i];
  for (int i = 0; i < 3; i++) {
    string cur;
    for (int j = 0; j < 3; j++) {
      cur.push_back(a[i][j]);
    }
    if (cur[0] == cur[1] && cur[1] == cur[2] && cur[0] != '.') {
      cout << cur[0] << '\n';
      return;
    }
  }
  for (int i = 0; i < 3; i++) {
    string cur;
    for (int j = 0; j < 3; j++) {
      cur.push_back(a[j][i]);
    }
    if (cur[0] == cur[1] && cur[1] == cur[2] && cur[0] != '.') {
      cout << cur[0] << '\n';
      return;
    }
  }
  if (a[0][0] == a[1][1] && a[0][0] == a[2][2] && a[0][0] != '.') {
    cout << a[0][0] << '\n';
    return;
  }
  if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][0] != '.') {
    cout << a[0][2] << '\n';
    return;
  }
  cout << "DRAW" << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}