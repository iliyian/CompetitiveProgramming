#include <bits/stdc++.h>
#define int long long

constexpr int len = 1414214;

// int pre[len];

std::vector<int> pre(len);

// void bf(int x) {
//   // for (int i = 0; i < len; i++) {}
//     if (v + v > x) break;
//     int vv = x - v;
//     if (*std::lower_bound(pre.begin(), pre.end(), vv) == vv) {
//       // std::cout << v << ' ' << vv << '\n';
//       std::cout << "YES\n";
//       return;
//       // return 1;
//     }
//   }
//   // return 0;
//   std::cout << "NO\n";
// }

void solve() {
  int x;
  std::cin >> x;
  int r = std::upper_bound(pre.begin(), pre.end(), x - pre[0]) - pre.begin();
  // int r = pre.size() - 1;
  // int r = std::upper_bound(pre, pre + len, x - pre[0]) - pre;
  for (int l = 0; l <= r; l++) {
    while (r > 0 && pre[l] + pre[r] > x) {
      r--;
    }
    if (pre[l] + pre[r] == x) {
      std::cout << "YES\n";
      // bf(x);
      return;
    }
  }
  std::cout << "NO\n";
  // bf(x);
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 0; i < 1414214; i++) {
    pre[i] = (i + 1) * (i + 2) / 2;
  }
  // std::cout << i << '\n';
  // for (int i = 1; i * i <= 1e12 * 8 + 2; i += 2) {
  //   pre.push_back(i * i);
  // }

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}