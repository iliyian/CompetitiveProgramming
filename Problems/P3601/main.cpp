#include <bits/stdc++.h>
#define mod 666623333
#define int long long
#define N 1000001
using namespace std;

bitset<N> vis;
void solve() {
  int l, r;
  cin >> l >> r;
  
  vector<int> pri;
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (auto p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      // i不适合作为因子了
      if (i % p == 0) break;
    }
  }
  vector<int> phi(N), minp(N);
  for (int i = l; i <= r; i++)
    phi[i - l] = i, minp[i - l] = i;
  for (int p : pri) {
    if (p * p > r) break;
    for (int x = (p - l % p) % p; x <= r - l; x += p) {
      // 依次计算贡献
      phi[x] = phi[x] / p * (p - 1);
      while (minp[x] % p == 0)
        minp[x] /= p;
    }
  }

  int ans = 0;
  for (int i = 0; i <= r - l; i++) {
    if (minp[i] > 1) phi[i] = phi[i] / minp[i] * (minp[i] - 1);
    ans = (ans + i + l - phi[i]) % mod;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int _ = 1;
  while (_--) solve();
}