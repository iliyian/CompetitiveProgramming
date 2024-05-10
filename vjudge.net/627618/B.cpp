#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int a, b;
  cin >> a >> b;
  // auto check = [&](int x) {
  //   for (int i = 0; i * a <= x; i++) {
  //     if ((x - i * a) % b == 0) {
  //       return true;
  //     }
  //   }
  //   return false;
  // };
  // for (int i = 2e4; i >= 1; i--) {
  //   if (!check(i)) {
  //     cout << i << '\n';
  //     break;
  //   }
  // }
  cout << (a - 1) * (b - 1) - 1 << '\n';

  return 0;
}