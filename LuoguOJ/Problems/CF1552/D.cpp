#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  sort(a.begin() + 1, a.end());
  int len = unique(a.begin() + 1, a.end()) - a.begin() - 1;
  if (len < n || n == 1) {
    cout << "YES\n";
    return;
  }
  for (int i = 0; i < (1 << len); i++) {
    int sum = 0;
    for (int j = 0; j < len; j++) {
      if ((i >> j) & 1) {
        sum += a[j + 1];
      }
    }
    if (sum)
  }
  cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}