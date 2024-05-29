#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    if ((n - i * 79) < 0) break;
    if ((n - i * 79) % 77 == 0) {
      int x = i;
      int y = (n - i * 79) / 77;
      cout << (y - 1) / 79 + 1 << '\n';
      return 0;
    }
  }
  cout << 0 << '\n';

  return 0;
}