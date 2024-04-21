#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      a.push_back(x);
    }
    for (int i = 0; i < m; i++) {
      int x; cin >> x;
      b.push_back(x);
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
      if (a[i] < a[x])
        x = i;
    for (int i = 0; i < m; i++)
      if (b[i] > b[y])
        y = i;

    if (a[x] < b[y]) {
      swap(a[x], b[y]);
    }
    if (k & 1 ^ 1) {
      x = y = 0;
      for (int i = 0; i < n; i++)
        if (a[i] > a[x])
          x = i;
      for (int i = 0; i < m; i++)
        if (b[i] < b[y])
          y = i;
      if (a[x] > b[y]) swap(a[x], b[y]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    cout << sum << '\n';
  }
}