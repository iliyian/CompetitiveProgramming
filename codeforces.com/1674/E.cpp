// date: 2024-05-02 14:00:57
// tag: 分类讨论

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = INT_MAX;
  auto calc = [&](auto self, int x, int y) -> int {
    if (x < y) swap(x, y);
    if (x >= y * 2) {
      return (x - 1) / 2 + 1;
    } else {
      return (x + y - 1) / 3 + 1;
    }
  };
  for (int i = 1; i <= n - 1; i++) {
    ans = min(ans, calc(calc, a[i], a[i + 1]));
  }
  for (int i = 2; i <= n - 1; i++) {
    ans = min(ans, (a[i - 1] + a[i + 1] - 1) / 2 + 1);
  }
  sort(a.begin() + 1, a.end());
  ans = min(ans, (a[1] - 1) / 2 + 1 + (a[2] - 1) / 2 + 1);
  cout << ans << '\n';

  return 0;
}