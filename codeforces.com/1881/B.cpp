// date: 2023/12/15
// tag: 整除往往是很多相等的必要条件

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] == a[1] && a[1] == a[2]) {
      cout << "YES\n";
    } else if (a[1] % a[0] || a[2] % a[0]) {
      cout << "NO\n";
    } else if (a[1] / a[0] + a[2] / a[0] > 5) {
      cout << "NO\n";
    } else cout << "YES\n";
  }
}