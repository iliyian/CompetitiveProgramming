#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a < b && b < c) {
    cout << "STAIR" << '\n';
  } else if (a < b && c < b) {
    cout << "PEAK\n";
  } else {
    cout << "NONE\n";
  }
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