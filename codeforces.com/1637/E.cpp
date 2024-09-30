// date: 2024-04-07 15:12:13
// tag: 暴力，卡常

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  set<tuple<int, int>> s;
  map<int, int> cnt;
  vector<int> a(n);
  vector<vector<int>> lis(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    s.insert({x, y});
    s.insert({y, x});
  }
  vector<int> cnts, vals;
  for (auto [x, c] : cnt) {
    cnts.push_back(c);
    vals.push_back(x);
    lis[c].push_back(x);
  }
  // sort(a.begin(), a.end());
  // a.erase(unique(a.begin(), a.end()), a.end());
  sort(cnts.begin(), cnts.end());
  cnts.erase(unique(cnts.begin(), cnts.end()), cnts.end());

  int ans = 0, res = 0;
  reverse(cnts.begin(), cnts.end());
  for (int i = 0; i < vals.size(); i++) {
    int x = vals[i];
    for (int j = 0; j <= cnt[x]; j++) {
      for (auto it = lis[j].rbegin(); it != lis[j].rend(); it++) {
        int y = *it;
        // res++;
        if (x == y || s.count({x, y})) {
          continue;
        }
        ans = max(ans, (x + y) * (cnt[x] + j));
        break;
      }
    }
  }
  cout << ans << '\n';
  // cout << res << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}