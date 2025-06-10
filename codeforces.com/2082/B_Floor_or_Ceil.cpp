#include <bits/stdc++.h>
#define int long long

void solve() {
  int x, n, m;
  std::cin >> x >> n >> m;
// void solve(int x, int n, int m) {
  int mn = x;
  n = std::min(n, 40ll);
  m = std::min(m, 40ll);
  int op1 = n, op2 = m;
  for (int i = 0; i <= 120; i++) {
    if (!op1 && !op2) break;
    if (x >> i & 1) {
    // if (mn % 2) {
      if (op2) {
        op2--;
        mn = (mn + 1) / 2;
      } else {
        op1--;
        mn = (mn + 0) / 2;
      }
    } else {
      if (op2) {
        op2--;
        mn = (mn + 1) / 2;
      } else {
        op1--;
        mn = (mn + 0) / 2;
      }
    }
    // std::cerr << mn << ' ' << op1 << ' ' << op2 << '\n';
  }
  // if (op1 || op2) mn = 0;
  int mx = x;
  op1 = n, op2 = m;
  for (int i = 0; i <= 120; i++) {
    if (!op1 && !op2) break;
    // if (x >> i & 1) {
    if (mx % 2) {
      if (op1) {
        op1--;
        mx = (mx + 0) / 2;
      } else {
        op2--;
        mx = (mx + 1) / 2;
      }
    } else {
      if (op1) {
        op1--;
        mx = (mx + 0) / 2;
      } else {
        op2--;
        mx = (mx + 1) / 2;
      }
    }
    // std::cerr << mx << ' ' << op1 << ' ' << op2 << '\n';
  }
  // if (op1 || op2) { // mx应为1或0
    // if (!op1 && mx != 0) mx = 1;
  // }
  // std::cout << x << ' ' << n << ' ' << m << ' ' << '\n';
  std::cout << mn << ' ' << mx << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
    // int lim = 10;
    // for (int x = 0; x <= 10; x++) {
    //   for (int n = 0; n <= 10; n++) {
    //     for (int m = 0; m <= 10; m++) {
    //       solve(x, n, m);
    //     }
    //   }
    // }
  }
  return 0;
}