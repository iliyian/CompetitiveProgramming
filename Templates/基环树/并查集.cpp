// date: 2024-06-07 23:11:40
// tag: 基环树，并查集，构造

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e5)
#define mod 998244353
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<int> pa(n + 1), siz(n + 1, 1), esiz(n + 1);
  vector<int> sloop(n + 1);

  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) {
      return;
    }
    pa[y] = x;
    siz[x] += siz[y];
    sloop[x] |= sloop[y];
  };
  iota(pa.begin() + 1, pa.end(), 1);
  
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) {
      sloop[a[i]] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    merge(a[i], b[i]);
  }
  for (int i = 1; i <= n; i++) {
    ++esiz[find(find, a[i])];
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (i == pa[i]) {
      if (esiz[i] != siz[i]) {
        cout << 0 << '\n';
        return;
      }
      if (sloop[i]) {
        ans = ans * n % mod;
      } else {
        ans = ans * 2 % mod;
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}