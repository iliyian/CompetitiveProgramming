// date: 2024-05-01 14:50:56
// tag: 构造，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  set<pair<int, int>> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s.insert({a[i], i});
  }
  
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] < s.rbegin()->first) {
      auto it = s.lower_bound({a[i], n + 1});
      ans[it->second] = a[i];
      s.erase(it);
    } else {
      ans[s.begin()->second] = a[i];
      s.erase(s.begin());
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << (ans[i] ? ans[i] : a[i]) << ' ';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F1.in", "r", stdin);
  freopen("F1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}