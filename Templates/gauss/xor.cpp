#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<bitset<2005>> a(m + 1);

  for (int i = 1; i <= m; i++) {
    string str;
    cin >> str;
    int x;
    cin >> x;
    for (int j = 0; j < str.size(); j++) {
      a[i][j + 1] = str[j] - '0';
    }
    a[i][n + 1] = x;
  }

  int r = 1, mx = 0;
  for (int c = 1; c <= n; c++) {
    r = c;
    while (r <= m && !a[r][c]) r++;
    if (r > m) {
      cout << "Cannot determine\n";
      return 0;
    }
    swap(a[r], a[c]);
    mx = max(r, mx);
    for (int i = 1; i <= m; i++) {
      if (i != c && a[i][c]) {
        a[i] ^= a[c];
      }
    }
  }
  cout << mx << '\n';
  for (int i = 1; i <= n; i++) {
    cout << (a[i][n + 1] ? "?y7M#" : "Earth") << '\n';
  }

  return 0;
}