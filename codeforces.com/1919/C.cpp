// date: 2024/02/07 22:26:43
// tag: 贪心，均匀分配
// 关键在保持有序和最小化操作即奥卡姆剃刀

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int m1 = 0x3f3f3f3f, m2 = 0x3f3f3f3f, ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (m1 >= x) m1 = x;
    else if (m2 >= x) m2 = x;
    else ans++, m1 = m2, m2 = x;
  }
  cout << ans << '\n';
}
// 4
// 7

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}