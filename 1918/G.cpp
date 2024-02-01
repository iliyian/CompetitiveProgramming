// date: 2024/02/01 15:42:36
// tag: 没有算法，纯粹找规律的智慧题

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 3 || n == 5) {
    cout << "NO\n";
    return;
  }
  vector<int> a = {1, 2}, b = {1, 2, -3, 2, 4, -5, -2};
  // a, b
  // a, b, -b, a - b
  // a, b, -b, a - b, b - a, b
  // 2 -2 4 1 -3 2 -3 -5 2
  // 
  cout << "YES\n";
  if (n & 1 ^ 1) {
    int x = 1, y = 2;
    for (int i = 0; i < n / 2; i++) {
      cout << x << ' ' << y << ' ';
      int nx = -y, ny = x - y;
      x = nx, y = ny;
    }
  } else {
    for (int i = 0; i < 7; i++)
      cout << b[i] << ' ';
    int x = -5, y = -2;
    for (int i = 0; i < (n - 7) / 2; i++) {
      int nx = -y, ny = x - y;
      x = nx, y = ny;
      cout << x << ' ' << y << ' ';
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // freopen("G.in", "r", stdin);
  // freopen("G.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}