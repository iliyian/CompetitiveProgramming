// date: 2024-05-12 17:10:30
// tag: 莫比乌斯反演

#include <bits/stdc++.h>
#define int long long
#define N ((int)5e4)
using namespace std;

vector<int> mu(N + 1), pri;
bitset<N + 1> vis;

void solve() {
  int a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  auto calc = [&](int x, int y) {
    x /= k, y /= k;
    int ans = 0;
    for (int l = 1, r; l <= min(x, y); l = r + 1) {
      r = min(x / (x / l), y / (y / l));
      ans += (mu[r] - mu[l - 1]) * (x / l) * (y / l);
    }
    return ans;
  };
  int ans = calc(b, d) - calc(a - 1, d) - calc(b, c - 1) + calc(a - 1, c - 1);
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

  for (int i = 2; i <= N; i++) {
    mu[i] += mu[i - 1];
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}