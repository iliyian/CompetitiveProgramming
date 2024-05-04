// date: 2024-05-03 12:00:03
// tag: 构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int cnt = n;
  for (int i = 1; i <= (n - 1) / 2 + 1; i++) {
    cout << n << ' ' << i << '\n';
    cnt--;
  }
  cout << 1 << ' ' << n << '\n';
  cnt--;
  for (int i = 0; i < cnt; i++) {
    cout << 1 << ' ' << n / 2 - i << '\n';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}