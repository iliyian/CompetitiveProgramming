// date: 2024-03-29 13:33:47
// tag: 排列组合，思维，构造，逆元

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define N 100005
using namespace std;

int fac[N];

void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int C(int n, int m) {
  int ans = fac[n] % mod, x, y;
  exgcd(fac[n - m], mod, x, y);
  x = (x % mod + mod) % mod;
  ans = ans * x % mod;
  exgcd(fac[m], mod, x, y);
  x = (x % mod + mod) % mod;
  ans = ans * x % mod;
  return ans;
}

void solve() {
  int n;
  string str;
  cin >> n >> str;
  int cnt0 = 0, cnt11 = 0, tmp = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '1') {
      tmp++;
      if (tmp == 2) {
        tmp = 0;
        cnt11++;
      }
    } else {
      cnt0++;
      tmp = 0;
    }
  }
  cout << C(cnt0 + cnt11, cnt11) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  fac[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}