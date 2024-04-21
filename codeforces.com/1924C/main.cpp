// date: 2024-03-20 23:00:01
// tag: 找规律，有理数取模

#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 999999893;

void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1ll;
  }
  return ans;
}

void solve() {
  int t;
  cin >> t;

  int ma = qpow(2, t / 2 + 1) - 2, mb, va, vb;
  if (t & 1) {
    mb = ma;
  } else {
    mb = ma - qpow(2, t / 2);
  }
  va = ma, vb = mb + 2;
  // cerr << format("{} {} {} {}", ma, mb, va, vb) << '\n';
  int deno = 2 * vb % mod * vb % mod - va * va % mod;
  deno = (deno % mod + mod) % mod;
  int nume = ma * vb % mod - mb * va % mod, x, y;
  nume = (nume % mod + mod) % mod;
  // assert(deno > 0);
  if (deno < 0) {
    cout << "!!!" << '\n';
    deno = -deno, nume = -nume;
  }
  int g = gcd(deno, nume);
  deno /= g, nume /= g;
  // cerr << format("{} {}", nume, deno) << '\n';
  exgcd(deno, mod, x, y);
  x = (x % mod + mod) % mod;
  int B = (nume % mod + mod) % mod * x % mod;
  cout << B << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}