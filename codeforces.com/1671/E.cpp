// date: 2024-04-30 19:37:16
// tag: 树，哈希

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define lc (p << 1)
#define rc (p << 1 | 1)
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(1 << n | 1);
  for (int i = 1; i <= (1 << n); i++) {
    char ch;
    cin >> ch;
    a[i] = ch == 'A';
  }
  vector<int> f(1 << n | 1, 1);
  auto dfs = [&](auto self, int p) -> string {
    if (lc > (1 << n) || rc > (1 << n))
      return string{char(a[p] + '0')};

    string l = self(self, lc);
    string r = self(self, rc);

    f[p] = f[lc] * f[rc] % mod;
    if (l != r) f[p] = f[p] * 2 % mod;
    if (l > r) swap(l, r);

    // cout << p << ' ' << l << ' ' << r << '\n';

    return string{char(a[p] + '0')} + l + r;
  };
  dfs(dfs, 1);
  cout << f[1] << '\n';

  return 0;
}