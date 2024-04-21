// date: 2024-04-01 16:10:30
// tag: 贪心，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string s, t;
  cin >> s >> t;
  int ps = 0, pt = 0;
  if (s.size() % 2 != t.size() % 2) ps++;
  while (ps < s.size() && pt < t.size()) {
    if (s[ps] != t[pt]) {
      ps += 2;
    } else {
      pt++;
      ps++;
    }
  }
  if (pt == t.size()) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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