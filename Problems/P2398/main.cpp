// date: 2024-03-16 15:41:53
// tag: 欧拉定理

#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

vector<int> phi(N), pri;
bitset<N> vis;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  for (int i = 2; i <= 100000; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      phi[i] = i - 1;
    }
    for (int p : pri) {
      if (i * p > 100000) break;
      vis[i * p] = true;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        break;
      }
      phi[i * p] = phi[i] * phi[p];
    }
  }
  vector<int> s(N);
  for (int i = 1; i <= 100000; i++) {
    s[i] = s[i - 1] + phi[i];
  }

  int n;
  cin >> n;
  int ans = (n + 1) * n / 2;
  for (int g = 1; g <= n; g++) {
    ans += 2 * g * s[n / g];
  }
  cout << ans << '\n';

  return 0;
}