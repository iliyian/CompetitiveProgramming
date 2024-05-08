// date: 2024-05-08 23:03:59
// tag: 整除分块，莫比乌斯反演

#include <bits/stdc++.h>
#define int long long
#define N 50000
using namespace std;

vector<int> mu(N + 1), pri;
bitset<N + 1> vis;

void solve() {
  int a, b, k;
  cin >> a >> b >> k;
  int ans = 0;
  a /= k, b /= k;
  for (int l = 1, r = 1; l <= min(a, b); l = r + 1) {
    r = min(a / (a / l), b / (b / l));
    ans += (mu[r] - mu[l - 1]) * (a / l) * (b / l);
    // \forall d \in [l,r], a/d \eq a/l \eq a/r \eq b/d
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  mu[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      mu[i] = -1;
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) {
        mu[i * p] = 0;
        break;
      }
      mu[i * p] = -mu[i];
    }
  }
  for (int i = 1; i <= N; i++) {
    mu[i] += mu[i - 1];
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}