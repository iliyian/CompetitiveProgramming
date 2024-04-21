// date: 2023/12/11
// tag: 树上操作与贪心
// 这题确实水得离谱...

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);
  int _; cin >> _;
  while (_--) {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
      cout << i + 1 << ' ' << i + 2 << '\n';
    int cur = n - 1;
    for (int i = 0; i < q; i++) {
      int d;
      cin >> d;
      if (d == cur) {
        cout << "-1 -1 -1\n";
      } else {
        cout << n << ' ' << cur << ' ' << d << '\n';
        cur = d;
      }
    }
  }
}