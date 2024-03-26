#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1ll) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1ll;
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  int ans = qpow(26, n);
  ans = ((ans - qpow(25, n) * 2 % mod) % mod + mod) % mod;
  ans = (ans + qpow(24, n)) % mod;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}