// date: 2023/12/15
// tag: dp, 标准dp，关键在定义状态和找到状态转移条件

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), f(n + 1);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  fill(f.begin(), f.end(), 0x3f3f3f3f);
  f[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i + a[i] + 1 <= n) f[i] = min(f[i], f[i + a[i] + 1]);
    f[i] = min(f[i], f[i + 1] + 1);
  }
  cout << f[0] << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}