// date: 2024/02/23 23:22:20
// tag: wa#01: 忽略了24行等于的情况，把它和l==r混淆了

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1), s(n + 1), ss(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    ss[i] = ss[i - 1] + (a[i] == 1 ? 2 : 1);
  }
  for (int t = 1; t <= q; t++) {
    int l, r;
    cin >> l >> r;
    int sum = s[r] - s[l - 1], summin = ss[r] - ss[l - 1];
    if (l == r) {
      cout << "NO\n";
    } else {
      if (sum >= summin) {
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

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}