#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (i) {
      int t = (i - 1) / 2 + 1;
      cout << (i % 2 ? t : -t) << ' ';
    } else {
      cout << i << ' ';
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}