#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;
  if (k < n || (k & 1) ^ (n & 1)) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  vector<vector<char>> a(2 * n + 2, vector<char>(2 * m + 2, '+'));
  for (int i = 2; i <= 2 * n + 1; i += 2) {
    for (int j = 2; j <= 2 * m + 1; j += 2) {
      a[i][j] = 'o';
    }
  }
  a[1][2 * m] = 'S';
  a[2 * n + 1][2 * m] = 'G';
  for (int i = 1; i <= 2 * n + 1; i++) {
    for (int j = 1; j <= 2 * m + 1; j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }
  int tot = (k - n) / 2;
  int c = m - ((tot - 1) % (m - 1) + 1);
  int r = (tot - 1) / (m - 1) * 2 + 1;

  if ()

  for (int i = 1; i <= r - 1; i++) {

  }
  
  cout << r << ' ' << c << '\n';

  return 0;
}