#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n + 1, vector<char>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  auto check = [&](char ch) {
    bool f = false;
    for (int i = 1; i <= n; i++) {
      if (a[i][1] == ch) {
        f = true;
        break;
      }
    }
    if (!f) return false;

    f = false;
    for (int i = 1; i <= n; i++) {
      if (a[i][m] == ch) {
        f = true;
        break;
      }
    }
    if (!f) return false;

    f = false;
    for (int i = 1; i <= m; i++) {
      if (a[1][i] == ch) {
        f = true;
        break;
      }
    }
    if (!f) return false;

    f = false;
    for (int i = 1; i <= m; i++) {
      if (a[n][i] == ch) {
        f = true;
        break;
      }
    }
    if (!f) return false;
    return true;
  };
  if (check('B') || check('W')) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}