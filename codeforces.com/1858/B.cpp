// date: 2024/02/08 12:18:44
// tag: 简单模拟，不能想复杂了

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(m + 2), s(m + 2), t(m + 1);
  bool f = false;
  a[0] = 1, a[m + 1] = n + 1; // 开区间
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 1; i <= m + 1; i++) {
    s[i] = ceil(double(a[i] - a[i - 1]) / d);
    sum += s[i];
  }
  int mi = 0x3f3f3f3f;
  for (int i = 1; i <= m; i++) {
    t[i] = sum - s[i] - s[i + 1] + ceil(double(a[i + 1] - a[i - 1]) / d);
    mi = min(mi, t[i]);
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += mi == t[i];
  }
  cout << mi << ' ' << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}