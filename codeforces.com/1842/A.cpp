#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int asum = 0, bsum = 0, x;
  for (int i = 0; i < n; i++)
    cin >> x, asum += x;
  for (int i = 0; i < m; i++)
    cin >> x, bsum += x;
  if (asum < bsum) {
    cout << "Tenzing\n";
  } else if (asum == bsum) {
    cout << "Draw\n";
  } else {
    cout << "Tsondu\n";
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}