// date: 2024-03-06 20:26:14
// tag: 数论分块

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  int ans = 0;

  vector<int> v;
  for (int i = 1; i <= n; i *= 2) {
    for (int j = i; j <= n; j *= 5) {
      v.push_back(j);
    }
  }
  sort(v.begin(), v.end());

  for (int l = 1, r = 1; l <= n; l = r + 1) {
    int t = n / l;
    r = n / t;
    int c = r - l + 1
      - (r / 2 - (l - 1) / 2) - (r / 5 - (l - 1) / 5)
      + (r / 10 - (l - 1) / 10);
    int a = upper_bound(v.begin(), v.end(), t) - v.begin();
    ans += a * c * t;
  }
  cout << ans << '\n';
  return 0;
}