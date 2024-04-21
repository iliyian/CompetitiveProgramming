#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int len = a[0].size();
  vector<vector<int>> f(len, vector<int>(1 << n));
  for (int i = 1; i < m; i++) {
    for (int S = (1 << n) - 1; S >= 0; S--) {
      f[i][S] += f[i - 1][]
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}