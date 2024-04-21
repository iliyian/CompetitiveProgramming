// date: 2024-03-14 08:18:19
// tag: re#01-05: O看成0了
// wa#06: ()<<1写成1<<()了
// wa#07: 可能是隐式类型转换出错
// wa#08: 没考虑到判断==在*后运行

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> a(m + 1), p(63);

  auto insert = [&](int x) {
    for (int i = 62; i >= 0; i--) {
      if ((x >> i) & 1ll) {
        if (p[i]) {
          x ^= p[i];
        } else {
          p[i] = x;
          return;
        }
      }
    }
  };

  for (int i = 1; i <= m; i++) {
    string x;
    cin >> x;
    for (int j = 0; j < x.size(); j++) {
      a[i] |= (1ll << j) * (x[j] == 'O');
    }
    insert(a[i]);
  }

  int ans = 0;
  for (int i = 62; i >= 0; i--) {
    if (p[i]) {
      ans++;
    }
  }
  cout << (1ll << ans) % 2008 << '\n';

  return 0;
}