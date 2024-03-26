// date: 2024-03-26 10:45:08
// tag: 树上最大/小连续子段和

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 200005
using namespace std;

void solve() {
  int n;
  cin >> n;
  char op;
  int x, y;
  int id = 1;
  vector<int> mx(n + 5, -inf), mn(n + 5, inf),
    allx(n + 5, -inf), alln(n + 5, inf);
  mx[1] = mn[1] = allx[1] = alln[1] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> op >> x >> y;
    if (op == '+') {
      ++id;
      mx[id] = max(y, mx[x] + y);
      mn[id] = min(y, mn[x] + y);
      allx[id] = max(allx[x], mx[id]);
      alln[id] = min(alln[x], mn[id]);
    } else {
      int k;
      cin >> k;
      if (min(0ll, alln[y]) <= k && k <= allx[y]) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}