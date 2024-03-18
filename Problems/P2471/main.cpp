// date: 2024-03-18 12:30:22
// tag: st表
// wa#01, re#02: 漏看一个条件
// wa#03: 细节太多了
// wa#04: 未知的情况输出成false了而非maybe

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> y(n + 1), r(n + 1);
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> y[i] >> r[i];
  };
  vector<vector<int>> st(n + 1, vector<int>(log2(n) + 10));
  for (int i = 1; i <= n; i++) {
    st[i][0] = r[i];
  }
  int logn = log2(n) + 10;
  for (int j = 1; j <= logn; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
    }
  }
  auto query = [&st](int l, int r) {
    int len = log2(r - l + 1) + 1;
    return max(st[l][len - 1], st[r - (1 << len - 1) + 1][len - 1]);
  };
  int q;
  cin >> q;
  for (int _ = 1; _ <= q; _++) {
    int s, t;
    cin >> s >> t;
    int xt = upper_bound(y.begin() + 1, y.end(), t) - y.begin() - 1;
    int xs = lower_bound(y.begin() + 1, y.end(), s) - y.begin();

    bool f = false;
    if (y[xt] != t && y[xs] != s) {
      cout << "maybe\n";
    }
    if (y[xt] == t && y[xs] == s) {
      if (r[xt] > r[xs]) {
        cout << "false" << '\n';
        continue;
      }
      if (xt == xs + 1) {
        cout << (t == s + 1 ? "true" : "maybe") << '\n';
        continue;
      }
      int mx = query(xs + 1, xt - 1);
      if (mx >= r[xt]) {
        cout << "false" << '\n';
        continue;
      }
      cout << (xt - xs == t - s ? "true" : "maybe") << '\n';
    }
    if (y[xt] != t && y[xs] == s) {
      if (xs == xt) {
        cout << "maybe\n";
      } else {
        int mx = query(xs + 1, xt);
        cout << (mx < r[xs] ? "maybe" : "false") << '\n';
      }
    }
    if (y[xt] == t && y[xs] != s) {
      if (xs == xt) {
        cout << "maybe\n";
      } else {
        int mx = query(xs, xt - 1);
        cout << (mx < r[xt] ? "maybe" : "false") << '\n';
      }
    }
  }
  return 0;
}