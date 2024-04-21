#include <bits/stdc++.h>
#define mod 100003
#define int long long
using namespace std;

int powmod(int m, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = ans * m % mod;
    m = m * m % mod;
    n >>= 1;
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // freopen("data.in", "r", stdin);
  int m, n;
  cin >> m >> n;
  int ans = powmod(m, n) % mod;
  int sub = m * powmod(m - 1, n - 1) % mod;
  cout << (ans + mod - sub) % mod;
  return 0;
}