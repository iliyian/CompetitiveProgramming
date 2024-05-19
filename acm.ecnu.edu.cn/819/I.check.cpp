#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("I.in", "r", stdin);
  freopen("I.ans", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> w(n + 1), v(n + 1);
  int sumw = 0, sumv = 0;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
    sumw += w[i], sumv += v[i];
  }
  vector<int> f(sumw + 1, -inf);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int W = sumw; W >= w[i]; W--) {
      f[W] = max(f[W], f[W - w[i]] + v[i]);
    }
  }
  for (int i = 1; i <= sumw; i++) {
    f[i] = max(f[i - 1], f[i]);
  }
  // for (int i = 1; i <= sumw; i++) {
  //   if (f[i] < f[i - 1]) {
  //     cout << "gg" << '\n';
  //     assert(false);
  //   }
  // }
  for (int i = 1; i <= m; i++) {
    int W;
    cin >> W;
    if (W >= sumw) {
      cout << sumv << '\n';
    } else {
      cout << f[W] << '\n';
    }
  }

  return 0;
}