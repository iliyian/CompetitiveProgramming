// date: 2024/02/22 20:23:59
// tag: bst的中序遍历不降性质，抽屉原理的转化
// （区间内给定长度的不降序列数量（也类似n元一次不定方程且x_n>=0的解的个数，左右各+n首先））
// 及C_{n}^{m} \eq C_{n}^{n-m}
// 这tmd爆long long了？
// wa#01: 漏了一处mod

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

vector<int> inv(500005);

void solve() {
  int n, C;
  cin >> n >> C;
  vector<int> val(n + 1), l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i] >> val[i];
  }
  vector<int> a = {0};
  auto dfs = [&](auto self, int x) -> void {
    if (l[x] != -1) self(self, l[x]);
    a.push_back(val[x]);
    if (r[x] != -1) self(self, r[x]);
  };
  auto calc = [](int lv, int rv, int len) -> int {
    int ans = 1;
    int x = len, y = rv - lv + 1;
    int n = x + y - 1, m = x;
    for (int i = n; i >= n - m + 1; i--) {
      ans = ans * i % mod;
    }
    for (int i = 2; i <= m; i++) {
      ans = ans * inv[i] % mod;
    }
    return ans;
  };
  dfs(dfs, 1);
  a.push_back(C);
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) {
      int lx = i, rx = i;
      while (a[rx] == -1) {
        rx++;
      }
      int lv = max(1ll, a[lx - 1]), rv = min(C, a[rx]);
      ans = ans * calc(lv, rv, rx - lx) % mod;
      i = rx - 1; 
    }
  }
  cout << ans << '\n';

  // for (auto i : a) {
  //   cout << i << ' ';
  // }
  // cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  inv[1] = 1;
  for (int i = 2; i <= 500004; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }

  while (_--) {
    solve();
  }

  return 0;
}