// date: 2024/02/08 15:40:31
// tag: wa#01: 嵌套三元表达式写串了
// P1654的弱化版

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  str = '#' + str;
  vector<double> x1(n + 1), ans(n + 1);
  for (int i = 1; i <= n; i++) {
    double p = (str[i] == '?' ? 0.5 : (str[i] == 'o' ? 1 : 0));
    x1[i] = (x1[i - 1] + 1) * p;
    ans[i] = ans[i - 1] + (2 * x1[i - 1] + 1) * p;
  }
  cout << fixed << setprecision(4) << ans[n] << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}