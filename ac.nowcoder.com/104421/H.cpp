#include <bits/stdc++.h>
#define F(i, x, n) for (int i = x; i <= n; ++i)
#define _F(i, x, n) for (int i = x; i >= n; --i)
#define ll long long
#define ull unsigned long long
#define lson x << 1
#define rson x << 1 | 1
#define lowbit(x) x & -x
#define en puts("")
#define int long long
using namespace std;

inline int read() {
  int s = 0;
  char c = getchar();
  bool flag = 0;
  while (!isdigit(c))
    flag |= (c == '-'), c = getchar();
  while (isdigit(c))
    s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  return flag ? -s : s;
}

const int N = 1e6 + 5;
const int mod = 998244353;

int qpow(int x, int y, int M) {
  int res = 1;
  for (; y; y >>= 1) {
    if (y & 1)
      res = res * x % M;
    x = x * x % M;
  }
  return res;
}
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

void solve() {
  int a = read(), b = read(), ans = 0;
  int M = mod - 1;
  map<int, int> mp;
  if (b <= 1e4) {
    F(i, 0, b) {
      int res = qpow(2ll, i, M) + M;
      ans = (ans + qpow(a, res, mod)) % mod;
    }
    cout << ans << "\n";
    return;
  }
  F(i, 23, 46) {
    int res = qpow(2ll, i, M) + M;
    mp[i - 23 + 1] = res;
  }
  vector<int> sum(35);
  F(i, 1, 24) sum[i] = (sum[i - 1] + qpow(a, mp[i], mod)) % mod;
  F(i, 0, 22) {
    int res = qpow(2ll, i, M) + M;
    ans = (ans + qpow(a, res, mod)) % mod;
  }
  b -= 22;
  ans = (ans + (b / 24) * sum[24] % mod + sum[b % 24]) % mod;
  cout << ans << "\n";
}

signed main() {
  int T = read();
  while (T--)
    solve();
  return 0;
}
