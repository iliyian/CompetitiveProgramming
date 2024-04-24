// date: 2024-04-24 22:27:05
// tag: 模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  bool f = true;
  while (f) {
    f = false;
    for (int i = 1; i <= n; i++) {
      int x = i, y = (i + 1) % n, z = (i + 2) % n;
      if (y == 0) y = n;
      if (z == 0) z = n;
      if (a[x] && a[y] && a[z]) {
        f = true;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      int j = (i + 1) % n;
      if (j == 0) j = n;
      a[j] = max(0ll, a[j] - a[i]);
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   cerr << a[i] << " \n"[i == n];
  // }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    int prv = i - 1 ? i - 1 : n;
    if (!a[prv] && a[i]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E2.in", "r", stdin);
  freopen("E1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}