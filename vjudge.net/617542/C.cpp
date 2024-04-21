#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  vector<int> pri, phi(5e6 + 1);
  vector<bool> vis(5e6 + 1);
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      phi[i] = i - 1;
    }
    for (int p : pri) {
      if (i * p > 5e6) break;
      vis[i * p] = true;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        break;
      }
      phi[i * p] = phi[i] * phi[p];
    }
  }

  return 0;
}