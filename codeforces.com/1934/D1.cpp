// date: 2024-03-03 13:21:17
// tag: wa: 输出不符题意
// wa没有输出k
// wa特判使用了0而非-1
// wa一处位运算没有用1ll

#include <bits/stdc++.h>
#define int long long
using namespace std;

// 1 1 0 0 0
// 0 0 0 1 1
void solve() {
  int n, m;
  cin >> n >> m;
  int a = -1, b = -1;
  for (int i = 62; i >= 0; i--) {
    if ((n >> i) & 1ll) {
      if (a == -1) a = i;
      else if (b == -1) b = i;
      else break;
    }
  }
  if (b == -1) {
    cout << -1 << '\n';
    return;
  }
  int c;
  for (int i = 62; i >= 0; i--) {
    if ((m >> i) & 1ll) {
      if (i == a) {
        cout << 1 << '\n';
        cout << n << ' ' << m << '\n';
        return;
      }
      if (i > b) {
        cout << -1 << '\n';
        return;
      }
      c = i;
      break;
    }
  }
  if ((1ll << b + 1) - 1 == m) {
    cout << 1 << '\n';
    cout << n << ' ' << m << '\n';
  } else {
    cout << 2 << '\n';
    cout << n << ' ' << (1ll << b + 1) - 1 << ' ' << m << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D1.in", "r", stdin);
  freopen("D1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}