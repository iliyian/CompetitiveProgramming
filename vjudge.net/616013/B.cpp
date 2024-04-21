#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> t(k + 1), x(k + 1), y(k + 1);
  for (int i = 1; i <= k; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  int ans = -1;

  auto exgcd = [](auto self, int a, int b, int &x, int &y) -> int {
    if (b == 0) {
      x = 1, y = 0;
      return a;
    }
    int g = self(self, b, a % b, y, x);
    y -= a / b * x;
    return g;
  };

  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++) {
      int lc = lcm(t[i], t[j]);
      int u =  x[i] - y[i] - (x[j] - y[j]);
      int v = y[j] * lc / t[j] - y[i] * lc / t[i];
      if (v && u % v == 0) {
        if (ans == -1) ans = u / v;
        else ans = min(ans, u / v);
      }
    }
  }
  if (ans == -1) {
    cout << "Mystia will cook forever..." << '\n';
    return 0;
  }
  cout << ans - 1 << '\n';

  return 0;
}