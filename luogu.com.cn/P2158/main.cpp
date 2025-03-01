// date: 2024-03-03 19:54:30
// tag: 秒杀

#include <bits/stdc++.h>
#define int long long
#define N 40005
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int t = 1;

  vector<bool> vis(N);
  vector<int> phi(N), pri;
  phi[1] = 1;
  for (int i = 2; i <= 40004; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      phi[i] = i - 1;
    }
    for (int p : pri) {
      if (p * i > 40000) break;
      vis[i * p] = true;
      if (i % p == 0) {
        phi[i * p] = p * phi[i];
        break;
      }
      phi[i * p] = phi[p] * phi[i];
    }
  }

  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 0 << '\n';
      return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n - 1; i++) {
      ans += phi[i];
    }
    cout << ans * 2 + 1 << '\n';
  }

  return 0;
}