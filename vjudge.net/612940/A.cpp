// date: 2024-03-12 10:40:44
// tag: 欧拉函数，莫比乌斯反演
// 

#include <bits/stdc++.h>
#define int long long
#define N 10000005
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  vector<int> pri, phi(N), g(N);
  vector<bool> vis(N);
  phi[1] = 1;
  g[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      phi[i] = i - 1;
      g[i] = i * (i - 1) + phi[1];
    }
    for (int p : pri) {
      if (i * p >= N) break;
      vis[i * p] = true;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        g[i * p] = (g[i] - g[i / p]) * (p * p + 1) + g[i / p];
        break;
      }
      phi[i * p] = phi[i] * phi[p];
      g[i * p] = g[i] * g[p];
    }
  }

  while (_--) {
    int n;
    cin >> n;
    cout << g[n] << '\n';
  }

  return 0;
}