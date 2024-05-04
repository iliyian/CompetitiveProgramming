#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int l = 0, r = 0;
  string a, b;
  cin >> a >> b;
  while (r < m) {
    while (r < m && a[l] != b[r]) {
      r++;
    }
    if (r < m) {
      l++, r++;
    }
  }
  cout << l << '\n';
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