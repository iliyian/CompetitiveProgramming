// date: 2024-06-04 12:35:56
// tag: 集合，图论，dp，连通性

#include <bits/stdc++.h>
#define int long long
#define N ((int)2e5)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int p;
  cin >> p;
  vector<int> f(p + 1, inf);
  f[0] = 0;
  for (int i = 1; i <= p; i++) {
    for (int j = 2; j * (j - 1) / 2 <= i; j++) {
      // 每j个独立的点形成一个新的scc
      f[i] = min(f[i], f[i - j * (j - 1) / 2] + j);
    }
  }
  // max{至少单连对数}-双连对数=max{仅单连对数}
  cout << f[p] << ' ' << f[p] * (f[p] - 1) / 2 - p << '\n';

  return 0;
}