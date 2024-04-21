// date: 2024/02/23 15:28:25
// tag: 沉着的找到各种数量规律

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int id = 2;
  while (k > (n - 1) / 2 + 1) {
    id *= 2;
    k -= (n - 1) / 2 + 1;
    n /= 2;
  }
  cout << id * k - id / 2 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}