// date: 2024/02/14 21:39:13
// tag: 考场上没做出来
// 总体上要进行分类讨论
// 并且要注意在思路失败时观察样例，本题样例过了直接AC

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

vector<int> inv(1000005);

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  auto C = [&](const int &n, const int &m) {
    int res = 1;
    for (int i = n; i >= n - m + 1; i--) {
      res = res * i % mod;
    }
    for (int i = 2; i <= m; i++) {
      res = res * inv[i] % mod;
    }
    return res;
  };
  // c+a 个球放入 a 个袋，隔板法要求每个未知数为正整数
  // \sum_{i=1}^{a}x_i \eq c, x_i>=0, 左右+a转换为x_i>=1
  // 视交错的1和2为基类
  int ans = 0;
  if (a - b >= 2 || b - a >= 2) {
    cout << "0\n";
    return;
  } else if (a == 0 && b == 0) {
    if (c && d) {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
    return;
  }
  if (a == b) {
    // 这tmd正反竟然不一样，还不能直接乘2
    ans = C(a + c - 1, a - 1) * C(b + 1 + d - 1, b + 1 - 1) % mod
      + C(a + 1 + c - 1, a + 1 - 1) * C(b + d - 1, b - 1) % mod;
    ans %= mod;
  } else if (a == b + 1) {
    ans = C(a + c - 1, a - 1) * C(b + 1 + d - 1, b + 1 - 1) % mod;
  } else if (b == a + 1) {
    ans = C(a + 1 + c - 1, a + 1 - 1) * C(b + d - 1, b - 1) % mod;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int t;
  cin >> t;

  inv[1] = 1;
  for (int i = 2; i <= 1000004; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }

  while (t--) {
    solve();
  }

  return 0;
}