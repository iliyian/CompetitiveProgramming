#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c != a + 1) {
    cout << -1 << '\n';
    return;
  }
  int r = (1 << (int)(ceil(log2(c))));
  if (b + c >= r) {
    b = b + c - r;
  } else {
    b = 0;
  }
  int h = (b ? (b - 1) / c + 1 : 0);
  h += (int)(ceil(log2(c)));
  cout << h << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}