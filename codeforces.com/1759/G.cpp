// date: 2024-06-02 20:47:42
// tag: 贪心，构造

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> b(n / 2 + 1);
  vector<int> vis(n + 1);
  for (int i = 1; i <= n / 2; i++) {
    cin >> b[i].first;
    b[i].second = i;
    vis[b[i].first]++;
  }
  // sort(b.begin() + 1, b.end());
  vector<int> ans(n + 1);
  set<int> s;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      s.insert(i);
    }
  }
  if (s.size() != n / 2) {
    cout << -1 << '\n';
    return;
  }

  for (int i = n / 2; i >= 1; i--) {
    auto p = s.lower_bound(b[i].first);
    if (p == s.begin()) {
      cout << -1 << '\n';
      return;
    }
    p = prev(p);
    ans[b[i].second] = *p;
    s.erase(p);
  }

  sort(b.begin() + 1, b.end(), [&](const pair<int, int> &x, const pair<int, int> &y) {
    return x.second < y.second;
  });
  for (int i = 1; i <= n / 2; i++) {
    cout << ans[i] << ' ' << b[i].first << ' ';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}