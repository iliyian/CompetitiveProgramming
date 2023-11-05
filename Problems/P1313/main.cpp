#include <bits/stdc++.h>
#define mod 10007
// #define int long long
// 真tmd好用
using namespace std;

int C[1001][1001];

int pow(int a, int b) {
  int base = a, ans = 1;
  base %= mod;
  while (b) {
    if (b & 1) ans = (ans % mod) * (base % mod) % mod;
    base = base * (base % mod) % mod;
    b >>= 1;
  }
  return ans % mod;
}

void initc(int k) {
  for (int i = 1; i <= k; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int a, b, k, n, m;
  cin >> a >> b >> k >> n >> m;
  initc(k);
  cout << C[k][n] * (pow(b, m) % mod) % mod * (pow(a, n) % mod) % mod;
  return 0;
}