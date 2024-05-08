#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  s = '0' + s + '0', t = '0' + t + '0';
  
  vector<int> ls, rs, lt, rt;
  for (int i = 1; i <= n + 1; i++) {
    if (s[i] != s[i - 1]) {
      if (s[i] == '1') {
        ls.push_back(i);
      } else {
        rs.push_back(i - 1);
      }
    }
    if (t[i] != t[i - 1]) {
      if (t[i] == '1') {
        lt.push_back(i);
      } else {
        rt.push_back(i - 1);
      }
    }
  }

  if (ls.size() != lt.size() || s[1] != t[1] || s[n] != t[n]) {
    cout << -1 << '\n';
    return;
  }

  int ans = 0;
  for (int i = 0; i < ls.size(); i++) {
    ans += abs(ls[i] - lt[i]) + abs(rs[i] - rt[i]);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}