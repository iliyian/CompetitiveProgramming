// date: 2024-04-14 21:20:11
// tag: 贪心，双指针，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin() + 1, a.end());
  int l = 1, r = n, d = 0;
  vector<int> ans(n + 1);
  while (l <= r) {
    bool f = false;
    if (a[r].first == r - l + 1 + d) {
      f = true;
      ans[a[r].second] = r - l + 1;
      d++;
      r--;
    }
    if (a[l].first == d - f) {
      if (f) {
        cout << "NO\n";
        return;
      }
      ans[a[l].second] = - (r - l + 1);
      f = true;
      l++;
    }
    if (!f) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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