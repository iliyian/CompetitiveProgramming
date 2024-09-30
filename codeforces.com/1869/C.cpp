// date: 2023/12/15
// tag: 先找到答案的上界，再根据答案找规律构造即可
// 根据答案推演过程

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  if (m == 1) {
    cout << 0 << '\n';
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cout << 0 << '\n';
  } else if (m >= n + 1) {
    cout << n + 1 << '\n';
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cout << (i + j + 1) % m << " \n"[j == m - 1];
  } else {
    cout << m << '\n';
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (i < m - 1)
          cout << (i + j + 1) % m << " \n"[j == m - 1];
        else
          cout << (i % (m - 1) + j + 1) % m << " \n"[j == m - 1];
      }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}