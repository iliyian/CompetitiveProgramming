#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> typ(n + 1, vector<int>(m + 1));
  vector<vector<int>> s(n + 1, vector<int>(m + 1));
  int suma = 0, sumb = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      cin >> ch;
      typ[i][j] = (ch == '1');
      if (typ[i][j]) {
        suma += a[i][j];
      } else {
        sumb += a[i][j];
      }
    }
  }
  vector<int> vis(n * m + 1);
  int d = abs(suma - sumb);
  if (d == 0) {
    cout << "YES\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      s[i][j] = typ[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
      if (i >= k && j >= k) {
        int sum = s[i][j] - s[i - k][j] - s[i][j - k] + s[i - k][j - k];
        int t = abs(k * k - sum * 2);
        vis[t] = true;
        if (t == 0) continue;
        if (d % t == 0) {
          cout << "YES\n";
          return;
        }
      }
    }
  }
  int g = 0;
  for (int i = 1; i <= n * m; i++) {
    if (vis[i]) {
      g = gcd(g, i);
    }
  }
  cout << (g == 0 || d % g ? "NO" : "YES") << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}