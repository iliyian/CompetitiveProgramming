#include <bits/stdc++.h>
#define mod 9901
#define int long long
using namespace std;

void exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int pow(int n, int p) {
  n %= mod;
  int ans = 1;
  while (p) {
    if (p & 1) ans = ans * n % mod;
    n = n * n % mod;
    p >>= 1;
  }
  return ans;
}

int ans = 1, a, b;

void handle(int i, int b) {
  int A = pow(i, b + 1) - 1, x, y;

  if (i % mod == 1) {
    ans = ans * (b + 1) % mod;
    return;
  }
  // 我还是搞不懂上面对乘法逆元不存在的处理
  // 1 ^ n == 1 ??

  exgcd(i - 1, mod, x, y);
  x = (x % mod + mod) % mod;
  int res = A * x % mod;
  ans = ans * res % mod;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> a >> b;
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      int p = b;
      a = a / i;
      while (a % i == 0) p += b, a /= i;
      handle(i, p);
      // if (a % i == i)
      //   handle(i, a, b);
    }
  }
  if (a != 1)
    handle(a, b);
  cout << (ans % mod + mod) % mod;
  return 0;
}