// date: 2024-04-30 12:56:55
// tag: 位运算，交互

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  auto ask = [](int a, int b) {
    cout << "? " << a << ' ' << b << '\n';
    cout.flush();
  };
  int cur = 0;
  for (int i = 0; i <= 29; i++) {
    int t = 1 << i;
    int a = t - cur;
    ask(a, a + (t << 1));
    int x;
    cin >> x;
    if (x == t << 1) {
      cur ^= 1 << i;
    }
    // cerr << t << ' ' << cur << '\n';
  }
  cout << "! " << cur << '\n';
  cout.flush();
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}