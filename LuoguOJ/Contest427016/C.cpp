#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  if (n % 2 && m % 2) {
    cout << -1 << '\n';
  } else {
    if (n % 2) {
      cout << 1 << '\n';
    } else if (m % 2) {
      cout << 2 << '\n';     
    } else {
      cout << 3 << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}