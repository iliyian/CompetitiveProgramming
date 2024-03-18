// date: 2024-03-18 14:17:45
// tag: Pollard_Rho, Miller_Rabin, 
// tle#01: qpow的longlong溢出了

#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937_64 rd(random_device{}());

int qpow(int a, int b, int p) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = __int128(ans) * a % p;
    a = __int128(a) * a % p;
    b >>= 1;
  }
  return ans;
}

bool Miller_Rabin(int p) {
  if (p < 2) return false;
  if (p == 2 || p == 3) return true;
  int d = p - 1, r = 0;
  while (d % 2 == 0) d >>= 1, r++;
  for (int t = 0; t < 10; t++) {
    int a = rd() % (p - 2) + 2;
    int x = qpow(a, d, p);
    if (x == 1 || x == p - 1) continue;
    for (int i = 0; i < r - 1; i++) {
      x = __int128(x) * x % p;
      if (x == p - 1) break;
    }
    if (x != p - 1) return false;
  }
  return true;
}

int Pollard_Rho(int x) {
  int s = 0, t = 0;
  int val = 1, c = rd() % (x - 1) + 1;
  for (int goal = 1;; goal *= 2, s = t, val = 1) {
    for (int step = 1; step <= goal; step++) {
      // assert(t != (__int128(t) * t + c) % x);
      t = (__int128(t) * t + c) % x;
      // assert(t != s);
      val = __int128(val) * abs(t - s) % x;
      if (step % 128 == 0) {
        int g = gcd(val, x);
        if (g > 1) return g;
      }
    }
    int g = gcd(val, x);
    if (g > 1) return g;
  }
}

int max_fac = 0;
void fac(int x) {
  if (x < 2 || x <= max_fac) return;
  if (Miller_Rabin(x)) {
    max_fac = max(max_fac, x);
    return;
  }
  int p = x;
  while (p >= x) p = Pollard_Rho(x);
  if (x % p == 0) x /= p;
  fac(x), fac(p);
}

void solve() {
  int n;
  cin >> n;
  max_fac = 0;
  fac(n);
  if (max_fac == n) {
    cout << "Prime\n";
  } else {
    cout << max_fac << '\n';
  }
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