// date: 2024-04-28 17:23:44
// tag: tmd逆序对倒着求才是tmd丝滑，本题同余逆序对

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  str = '#' + str;
  vector<int> a(n + 1);
  vector<array<int, 3>> d(n * 2 + 2, {0, 0, 0});
  auto add = [&](int x, int c, int m) {
    for (int i = x; i <= n * 2 + 1; i += i & -i) {
      d[i][m] += c;
    }
  };
  auto sum = [&](int x, int m) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      ans += d[i][m];
    }
    return ans;
  };
  int ans = 0;
  auto mo = [&](int x) {return (x % 3 + 3) % 3;};
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + (str[i] == '+' ? 1 : -1);
  }
  for (int i = n; i >= 0; i--) {
    ans += sum(a[i] + n + 1, mo(a[i]));
    add(a[i] + n + 1, 1, mo(a[i]));
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F2.in", "r", stdin);
  freopen("F2.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}