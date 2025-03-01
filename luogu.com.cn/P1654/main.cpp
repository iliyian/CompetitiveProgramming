// date: 2024/02/08 15:13:44
// tag: 类似于动态规划的概率题，计算思路和用线段树维护方差差不多，
// 即将计算方法分解，分别维护

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  double cur;
  vector<double> x1(n + 1), x2(n + 1), ans(n + 1);
  for (int i = 1; i <= n; i++) {
    double p;
    cin >> p;
    x1[i] = (x1[i - 1] + 1) * p;
    x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1) * p;
    ans[i] = ans[i - 1] + (3 * x2[i - 1] + 3 * x1[i - 1] + 1) * p;
  }
  cout << fixed << setprecision(1) << ans[n] << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}