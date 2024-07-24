#include <bits/stdc++.h>
#define int long long
#define N ((int)1e7 + 50)
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  vector<int> pri;

  bitset<N> vis;

  for (int i = 2; i < N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p >= N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int p, x, k;
  cin >> p >> k >> x;

  for (int pr : pri) {
    if (p % pr == 0) {
      
    }
  }

  return 0;
}