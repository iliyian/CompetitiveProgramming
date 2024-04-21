#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int t = 0;
  vector<vector<int>> a(n * 2 + 1, vector<int>(n * 2 + 1));
  for (int i = 1; i <= n * 2; i += 2) {
    for (int j = 1; j <= n * 2; j += 2) {
      for (int p = 0; p < 2; p++) {
        for (int k = 0; k < 2; k++) {
          a[i + p][j + k] = (((i / 2) % 2) == ((j / 2) % 2));
        }
      }
    }
  }
  for (int i = 1; i <= n * 2; i++) {
    for (int j = 1; j <= n * 2; j++) {
      cout << (a[i][j] ? "#" : ".");
    }
    cout << "\n";
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