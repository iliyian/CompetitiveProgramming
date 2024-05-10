// date: 2024-05-09 14:04:39
// tag: 暴力，模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int zcnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    zcnt += !a[i] && i;
  }
  vector<int> prv = a, cur;
  bool f = false;
  while (zcnt || prv.size() > 1) {
    sort(prv.begin(), prv.end());
    if (zcnt > 0) {
      cur.push_back(prv.front());
    }
    for (int i = 1; i < prv.size(); i++) {
      if (prv[i]) {
        cur.push_back(prv[i] - prv[i - 1]);
        zcnt += prv[i] == prv[i - 1];
      }
    }
    prv = cur;
    cur.clear();
    if (zcnt > 0) zcnt--;
  }
  cout << prv.front() << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}