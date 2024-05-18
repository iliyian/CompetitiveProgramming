// date: 2024-05-17 21:30:06
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int cur = 0;
  vector<int> ans;
  vector<int> vis(n + 1);
  for (int i = 30; i >= 0; i--) {
    int mx = 0;
    for (int j = 1; j <= n; j++) {
      if (vis[j]) continue;
      if ((cur | a[j]) > (cur | a[mx])) {
        mx = j;
      }
    }
    cur |= a[mx];
    if (mx) {
      vis[mx] = true;
      ans.push_back(a[mx]);
    }
  }
  for (auto i : ans) {
    cout << i << ' ';
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cout << a[i] << ' ';
    }
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