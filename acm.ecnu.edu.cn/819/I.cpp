#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("I.in", "r", stdin);
  freopen("I.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> w(n + 1), v(n + 1);
  int sumw = 0, sumv = 0;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
    sumw += w[i];
    sumv += v[i];
  }
  vector<int> f(((int)1e5) + 5, inf);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int V = sumv; V >= v[i]; V--) {
      f[V] = min(f[V], f[V - v[i]] + w[i]);
    }
  }
  for (int i = sumv - 1; i >= 0; i--) {
    f[i] = min(f[i + 1], f[i]);
  }

  for (int i = 1; i <= m; i++) {
    int W;
    cin >> W;
    if (W >= sumw) {
      cout << sumv << '\n';
    } else {
      cout << prev(upper_bound(f.begin(), f.begin() + sumv + 1, W)) - f.begin() << '\n';
    }
  }

  return 0;
}