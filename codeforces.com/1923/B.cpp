// date: 2024/02/23 23:05:54
// tag: wa#01: 29行位置正负没处理好

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), x(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  vector<int> id(n + 1);
  iota(id.begin() + 1, id.end(), 1);
  sort(id.begin() + 1, id.end(), [&](const int &u, const int &v) {
    if (abs(x[u]) == abs(x[v])) {
      return a[u] < a[v];
    }
    return abs(x[u]) < abs(x[v]);
  });
  int t = 0;
  for (int i = 1; i <= n; i++) {
    if (!a[id[i]]) continue;
    if (x[id[i]] > 0 && x[id[i]] <= t || x[id[i]] < 0 && abs(x[id[i]]) <= t) {
      cout << "NO\n";
      return;
    }
    int cur = k;
    for (int j = i; j <= n; j++) {
      if (cur > a[id[j]]) {
        cur -= a[id[j]];
        a[id[j]] = 0;
      } else {
        a[id[j]] -= cur;
        cur = 0;
        break;
      }
    }
    if (a[id[i]] > 0) i--;
    t++;
  }
  cout << "YES\n";
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