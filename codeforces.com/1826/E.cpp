// date: 2024-04-13 19:45:17
// tag: bitset优化的高维偏序与dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

bitset<5000> b[5000];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int m, n;
  cin >> m >> n;
  vector<int> a(n), id(n);
  vector<vector<int>> r(m, vector<int>(n));
  iota(id.begin(), id.end(), 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans = max(ans, a[i]);
    b[i].set();
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> r[i][j];
    }
  }
  for (int d = 0; d < m; d++) {
    auto cmp = [&](const int &x, const int &y) {
      return r[d][x] < r[d][y];
    };
    sort(id.begin(), id.end(), cmp);
    bitset<5000> now;
    for (int i = 0; i < n; i++) {
      int j = i;
      // tmd这里没用id找的我好苦啊
      while (j < n - 1 && r[d][id[j + 1]] == r[d][id[i]]) j++;
      for (int k = i; k <= j; k++) {
        b[id[k]] &= now;
      }
      for (int k = i; k <= j; k++) {
        now[id[k]] = 1;
      }
      i = j;
    }
  }
  // f和a的下标含义不一样，f是第m+1维，即正序，原始序
  // f的下标本身就是被映射者，f本身已经不需要再映射了
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    f[i] = a[id[i]];
    for (int j = 0; j < i; j++) {
      if (b[id[i]][id[j]]) {
        f[i] = max(f[i], a[id[i]] + f[j]);
        ans = max(ans, f[i]);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}