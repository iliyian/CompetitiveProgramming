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
  vector<vector<int>> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i][j];
  }
  vector<int> p(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= m; i++) {
    for (int S = (1 << n) - 1; S >= 0; S--) {
      
    }
  }

  return 0;
}