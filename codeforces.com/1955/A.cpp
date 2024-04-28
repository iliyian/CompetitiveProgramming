#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (b >= a * 2) {
    cout << n * a << '\n';
  } else {
    cout << n / 2 * b + (n % 2) * a << '\n';
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