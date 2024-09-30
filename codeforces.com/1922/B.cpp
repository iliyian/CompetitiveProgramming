// date: 2024/01/29 13:01:04
// tag: 排列组合，注意审题，数据是指数

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x]++;
  }
  int sum = 0, ans = 0;
  for (auto [x, cnt] : m) {
    if (cnt >= 3)
      ans += cnt * (cnt - 1) * (cnt - 2) / 6;
    if (cnt >= 2)
      ans += cnt * (cnt - 1) / 2 * sum;
    sum += cnt;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}