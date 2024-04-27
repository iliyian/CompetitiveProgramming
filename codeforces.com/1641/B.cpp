// date: 2024-04-25 12:55:21
// tag: 构造，暴力

#include <bits/stdc++.h>
#define int long long
#define N 500
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> add;
  vector<int> ans;
  int pre = 0;
  while (!a.empty()) {
    bool f = false;
    for (auto it = a.begin() + 1; it != a.end(); it++) {
      if (*it == a.front()) {
        f = true;
        int len = 1;
        for (auto it2 = a.begin() + 1; it2 != it; it2++) {
          add.push_back({it - a.begin() + it2 - a.begin() + pre, *it2});
          len++;
        }
        reverse(a.begin() + 1, it);
        a.erase(it);
        a.erase(a.begin());
        ans.push_back(len * 2);
        pre += len * 2;
        break;
      }
    }
    if (!f) {
      cout << -1 << '\n';
      return;
    }
  }

  cout << add.size() << '\n';
  for (auto [k, v] : add) {
    cout << k << ' ' << v << '\n';
  }
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}