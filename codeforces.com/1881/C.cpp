#include <bits/stdc++.h>
#define N 1005
using namespace std;

char a[N][N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  int len = n >> 1, ans = 0;
  for (int i = 0; i < len; i++)
    for (int j = 0; j < len; j++) {
      int x1 = j, y1 = n - 1 - i;
      int x2 = n - 1 - j, y2 = i;
      int x3 = n - 1 - i, y3 = n - 1 -j;
      int ma = max(max(a[i][j], a[x1][y1]), max(a[x2][y2], a[x3][y3]));
      ans += ma * 4 - a[x1][y1] - a[x2][y2] - a[x3][y3] - a[i][j];
    }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}