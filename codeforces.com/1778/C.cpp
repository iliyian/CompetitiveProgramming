// date: 2024-06-14 21:25:34
// tag: 暴力，
// 看起来常数很小，1e8了都

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string a, b;
  cin >> a >> b;
  string s = a;
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  vector<int> pos(26);
  for (int i = 0; i < s.size(); i++) {
    pos[s[i] - 'a'] = i;
  }
  int ans = 0;
  for (int S = 0; S < (1 << s.size()); S++) {
    if (__builtin_popcount(S) <= k) {
      int len = 0;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (S >> pos[a[i] - 'a'] & 1 || a[i] == b[i]) {
          len++;
        } else {
          cnt += len * (len + 1) / 2;
          len = 0;
        }
      }
      cnt += len * (len + 1) / 2;
      ans = max(ans, cnt);
    }
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}