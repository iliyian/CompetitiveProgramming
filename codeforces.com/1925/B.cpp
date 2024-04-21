#include <bits/stdc++.h>
#define int long long
using namespace std;
// vector<vector<int>> fac(1e8);
vector<int> pri;
bitset<100000001> vis;

void solve() {
  int x, n;
  cin >> x >> n;

  int ans = 0;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      if (n <= x / i) {
        ans = max(ans, i);
      }
      if (n <= i) {
        ans = max(ans, x / i);
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _; cin >> _;
  while (_--) solve();
}