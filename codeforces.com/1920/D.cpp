#include <bits/stdc++.h>
#define inf (long long)1e18
#define int long long
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> a(1);
  vector<int> len{0}, mul{1};
  for (int i = 0; i < n; i++) {
    int b, x;
    cin >> b >> x;
    if (b == 1) {
      a.back().push_back(x);
    } else {
      if (len.back() < inf) {
        len.push_back(len.back() <= inf / mul.back() ? len.back() * mul.back() + a.back().size() : inf);
        mul.push_back(x + 1);
        a.push_back({});
      }
    }
  }
  while (q--) {
    int k; cin >> k; k--;
    for (int i = a.size() - 1; i >= 0; i--) {
      if (k / mul[i] >= len[i]) {
        cout << a[i][k - len[i] * mul[i]] << " \n"[q == 0];
        break;
      }
      k %= len[i];
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}