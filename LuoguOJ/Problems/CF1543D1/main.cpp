// date: 2024-03-29 17:39:10
// tag: 异或性质，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cout << (i ? (i ^ (i - 1)) : i) << '\n';
    cout.flush();
    int x;
    cin >> x;
    if (x) {
      break;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("main.in", "r", stdin);
  // freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}