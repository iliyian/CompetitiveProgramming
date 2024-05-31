// date: 2024-05-30 17:53:54
// tag: 模拟，暴力

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, p;
  cin >> n >> p;
  vector<int> a(n + 1);
  set<int> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  for (auto it = s.lower_bound(a[n]);; it--) {
    if (*prev(it) != *it - 1 && it != s.begin() || it == s.begin() && *it != 0)  {
      
      vector<int> b = a;
      b[n] += p - b[n];
      for (int i = n; i >= 1; i--) {
        b[i - 1] += b[i] / p;
        b[i] %= p;
        s.insert(b[i]);
      }
      if (b[0]) s.insert(b[0]);

      it = s.lower_bound(a[n]);
      for (; it != s.begin(); it--){
        if (*prev(it) != *it - 1) {
          cout << *it - 1 + p - a[n] << '\n';
          return;
        }
      }
      cout << p - a[n] << '\n';
      return;
    }
    if (it == s.begin()) break;
  }
  if (*s.begin() != 0) {
    cout << p - a[n] + *s.begin() - 1 << '\n';
    return;
  }

  // 不进位
  if (!s.count(p - 1)) {
    cout << p - 1 - a[n] << '\n';
    return;
  }
  for (auto it = prev(s.end()); *it != a[n]; it--) {
    if (*prev(it) != *it - 1) {
      cout << *it - 1 - a[n] << '\n';
      return;
    }
  }
  cout << 0 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}