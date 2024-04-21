#include <bits/stdc++.h>
#define mod 1000000007
#define int unsigned long long
using namespace std;

int a[100005];

void gen() {
  a[1] = a[0] = 1;
  for (int i = 2; i <= 100004; i++)
    a[i] = (a[i - 1] + a[i - 2]) % mod;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  string str;
  cin >> str;
  gen();
  int ncnt = 0, ucnt = 0, ans = 1;
  for (auto &ch : str) {
    if (ch == 'm' || ch == 'w') {
      cout << 0;
      return 0;
    }
    if (ch == 'n' && !ucnt) ncnt++;
    else if (ch == 'u' && !ncnt) ucnt++;
    else {
      if (ncnt > 0) {
        ans *= a[ncnt];
        ans %= mod;
      } else if (ucnt > 0) {
        ans *= a[ucnt];
        ans %= mod;
      }

      ncnt = ucnt = 0;
      ncnt += ch == 'n', ucnt += ch == 'u';
    }
  }

  if (ncnt > 0) {
    ans *= a[ncnt];
    ans %= mod;
  } else if (ucnt > 0) {
    ans *= a[ucnt];
    ans %= mod;
  }

  cout << ans;
}