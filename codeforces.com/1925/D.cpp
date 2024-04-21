#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

// p mod m*q=x

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int d = (n - 1) * n / 2;
  int ini = 0;
  for (int i = 0; i < m; i++) {
    int a, b, f;
    cin >> a >> b >> f;
    ini += f;
  }
  vector<int> C(k + 1);
  C[0] = 1;
  int c = 1;
  vector<int> inv(k + 1);
  inv[1] = 1;
  for (int i = 2; i <= k; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
  auto exgcd = [&](auto self, int a, int b, int &x, int &y) {
    if (b == 0) {
      x = 1, y = 0;
      return;
    }
    self(self, b, a % b, y, x);
    y -= a / b * x;
  };
  for (int i = 1; i <= k; i++) {
    if (k - i < i) {
      C[i] = C[k - i];
    } else {
      c = c * (k - i + 1) % mod / i % mod;
      C[i] = c % mod;
    }
  }

  int invd, y;
  exgcd(exgcd, d, mod, invd, y);
  d = (n - 1) * n / 2;
  vector<int> powd(k + 1), powd1(k + 1);
  powd[0] = powd1[0] = 1;
  for (int i = 1; i <= k; i++) {
    powd[i] = powd[i - 1] * invd % mod;
    powd1[i] = powd1[i - 1] * (d - 1) % mod;
  }
  vector<int> P(k + 1);
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    P[i] = (n > 2 ? C[i] * (powd1[k - i] % mod * powd[i] % mod : ) % mod;
    ans = (ans + P[i] * (((i + 1) * i / 2) % mod) % mod) % mod;
  }
  ans = ans * m % mod;
  ans = (ans + ini) % mod;
  cout << ans << '\n';
}
// P(x)=C(k,x)*(1/d)^(x)*((d-1)/d)^(k-x)
// sum_{x=0}^{k}{(x+1)*x/2}P(x)

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}