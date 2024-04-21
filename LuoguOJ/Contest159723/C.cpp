#include <bits/stdc++.h>
#define int long long
#define mod 722733748
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int a, q, k;
  cin >> k >> a >> q;

  // 3 
  int cur = a % mod, ans = a % mod;
  for (int i = 2; i <= k; i++) {
    cur = cur * q % mod;
    ans = ans * cur % mod;
  }
  cout << ans % mod << '\n';

  return 0;
}