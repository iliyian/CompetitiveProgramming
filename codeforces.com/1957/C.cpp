#include <bits/stdc++.h>
#define int long long
#define N 300000
#define mod (int)(1e9 + 7)
using namespace std;

vector<int> f(N + 5), inv(N + 5), cn(N + 5);

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int r, c;
    cin >> r >> c;
    if (r == c) n--;
    else n -= 2;
  }

  vector<int> cn(n + 1);
  cn[0] = 1;
  for (int i = 1; i <= n; i++) {
    cn[i] = cn[i - 1] * (n - i + 1) % mod * inv[i] % mod;
  }
  int ans = 0;

  for (int i = n; i >= 0; i -= 2) {
    ans += cn[i] * f[n - i] % mod;
    ans %= mod;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  f[0] = inv[1] = 1;
  for (int i = 2; i <= N; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
  f[2] = 2;
  for (int i = 4; i <= N; i += 2) {
    f[i] = f[i - 2] * (2 * i - 2) % mod;
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}