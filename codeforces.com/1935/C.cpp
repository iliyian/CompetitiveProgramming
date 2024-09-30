#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, lim;
  cin >> n >> lim;
  vector<pair<int, int>> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin() + 1, v.end(), [&](const pair<int, int> &x, const pair<int, int> &y) {
    if (x.second == y.second) {
      return x.first < y.first;
    }
    return x.second < y.second;
  });
  vector<int> s(n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + v[i].first;
  }
  int ans = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = l + 1; r <= n; r++) {
      int tot = v[r].second - v[l].second + v[l].first + v[r].first;
      vector<int> cur;
      for (int i = l + 1; i <= r; i++) {
        cur.push_back(v[i].first);
        
      }
      ans = max(ans, 2 + idx - l);
    }
  }
  if (!ans) {
    for (int i = 1; i <= n; i++) {
      if (v[i].first < lim) {
        ans = 1;
        break;
      }
    }
  }
  cout << ans << '\n';
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