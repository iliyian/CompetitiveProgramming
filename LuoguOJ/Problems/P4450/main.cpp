// date: 2024-05-12 16:46:01
// tag: 莫比乌斯反演

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e6)
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int A, B, d;
  cin >> A >> B >> d;
  vector<int> pri, mu(N + 1);
  bitset<N + 1> vis;

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
  int ans = 0;
  A /= d, B /= d;
  for (int l = 1, r = 1; l <= min(A, B); l = r + 1) {
    r = min(A / (A / l), B / (B / l));
    ans += (mu[r] - mu[l - 1]) * (A / l) * (B / l);
  }
  cout << ans << '\n';

  return 0;
}