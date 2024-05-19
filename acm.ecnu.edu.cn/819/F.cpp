#include <algorithm>
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, a, b;
  cin >> n >> a >> b;
  vector<int> w(n + 1), t(n + 1);
  array<vector<int>, 3> lis;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    lis[t[i]].push_back(i);
  }

  auto prv = [&](int ti, int x) -> int {
    int pos = lower_bound(lis[ti].begin(), lis[ti].end(), x) - lis[ti].begin() - 1;
    if (pos < 0) return 0;
    return lis[ti][pos];
  };

  vector<array<int, 2>> f(n + 1, {-inf, -inf});
  f[0] = {0, 0};
  for (int i = 1; i <= n; i++) {
    f[i][0] = max({f[i - 1][0], f[i - 1][1]});
    int prv_same = prv(t[i], i - (t[i] == 1 ? a : b));
    int prv_dif = prv(t[i] == 1 ? 2 : 1, i);
    f[i][1] = w[i] + max({f[prv_dif][1], f[prv_dif][0], f[prv_same][1], f[prv_same][0]});
  }
  cout << max({f[n][0], f[n][1]}) << '\n';

  return 0;
}