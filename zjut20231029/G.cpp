#include <bits/stdc++.h>
#define int unsigned long long
#define mod 998244353
using namespace std;

int m(int x) {
  return x % mod;
}

signed main() {
  freopen("G.in", "r", stdin);
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << ((m(a) * m(b) % mod * m(c) % mod) - (m(d) * m(e) % mod * m(f) % mod) + mod) % mod;
  return 0;
}