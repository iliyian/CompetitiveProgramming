#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("primes.in", "r", stdin);
  freopen("primes.out", "w", stdout);

  int l = 19200000000, r = 19300000000;
  int lim = 140000;
  vector<int> pri;
  vector<bool> vis(lim);
  for (int i = 2; i < lim; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p >= lim) break;
      vis[i * p] = true;
      if (i % p == 0) {
        break;
      }
    }
  }
  vector<bool> vis2(r - l + 1);
  for (int p : pri) {
    int s = (l - 1) / p + 1;
    for (int i = s; i * p <= r; i++) {
      vis2[i * p - l] = true;
    }
  }
  for (int i = 0; i < r - l + 1; i++) {
    if (!vis2[i]) {
      cout << l + i << '\n';
    }
  }

  return 0;
}