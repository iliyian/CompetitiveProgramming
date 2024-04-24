// date: 2024-04-24 17:53:45
// tag: 

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i * (i * 2 - 1);
  }
  cout << ans << ' ' << n * 2 << '\n';
  auto print = [](int x) {
    for (int i = 1; i <= x; i++) {
      cout << i << ' ';
    }
    cout << '\n';
  };
  for (int i = n; i >= 1; i--) {
    cout << 1 << ' ' << i << ' ';
    print(n);
    cout << 2 << ' ' << i << ' ';
    print(n);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}