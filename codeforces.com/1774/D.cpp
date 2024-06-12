// date: 2024-06-10 20:23:26
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  vector<int> cnt(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      cnt[i] += a[i][j] == 1;
    }
    sum += cnt[i];
  }
  if (sum % n) {
    cout << -1 << '\n';
    return;
  }
  vector<tuple<int, int, int>> ans;
  for (int j = 1; j <= m; j++) {
    vector<int> more, less;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] > sum / n && a[i][j] == 1) {
        more.push_back(i);
      }
      if (cnt[i] < sum / n && a[i][j] == 0) {
        less.push_back(i);
      }
      if (!more.empty() && !less.empty()) {
        ans.push_back({more.back(), less.back(), j});
        cnt[more.back()]--, cnt[less.back()]++;
        more.pop_back(), less.pop_back();
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto [x, y, z] : ans) {
    cout << x << ' ' << y << ' ' << z << '\n';
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;  

  while (_--) {
    solve();
  }

  return 0;
}