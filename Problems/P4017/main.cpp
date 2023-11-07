#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;

int f[100001], inv[100001], A[100001];

void init() {
  f[1] = 0;
  f[2] = 1;
  inv[1] = 1;
  inv[2] = (long long)(mod - mod / 2) * inv[mod % 2] % mod;
  A[1] = 1, A[2] = 2;
  for (int i = 3; i <= 100000; i++) {
    f[i] = (i - 1) * ((f[i - 1] + f[i - 2]) % mod) % mod;
    // inv[i] = (mod - mod / i) % mod * inv[mod % i] % mod;
    A[i] = A[i - 1] * i % mod;
  }
}

void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int C(int n, int m) {
  int ans = A[n], x, y;

  exgcd(A[m], mod, x, y);
  x = (x % mod + mod) % mod;
  ans = ans * x % mod;

  exgcd(A[n - m], mod, x, y);
  x = (x % mod + mod) % mod;
  ans = ans * x % mod;

  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  cout << C(n, m) * f[n - m] % mod << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T; cin >> T;
  init();
  while (T--) solve();
  return 0;
}