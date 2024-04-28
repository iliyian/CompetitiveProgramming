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
  auto mo = [&](int x) {return (x % 3 + 3) % 3;};
  int ans = 0;
  add(n + 1, 1, 0);
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + (str[i] == '+' ? 1 : -1);
    ans += sum(n * 2 + 1, mo(a[i]))
      - sum(a[i] + n, mo(a[i]));
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