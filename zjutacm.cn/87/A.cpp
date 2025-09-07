#include <bits/stdc++.h>
#define int long long

void solve() {
  int m, n;
  std::cin >> m >> n;
  std::string s = "jhjhjjhjhjhj";
  std::string str;
  for (int i = 0; i < 40; i++) {
    str += s;
  }
  for (int l = 0; l < str.size(); l++) {
    for (int r = l; r < str.size(); r++) {
      int cj = 0, ch = 0;
      for (int i = l; i <= r; i++) {
        cj += str[i] == 'j';
        ch += str[i] == 'h';
      }
      if (cj == m && ch == n) {
        std::cout << "Yes\n";
        return;
      }
    }
  }
  std::cout << "No\n";
}

// void solve() {
//   int m, n;
//   std::cin >> m >> n;
//   int x = 7, y = 5;
//   std::string s = "jhjhjjhjhjhj";
//   for (int l = 0; l < s.size(); l++) {
//     for (int r = l; r < s.size(); r++) {
//       int cj = 0, ch = 0;
//       for (int i = l; i <= r; i++) {
//         cj += s[i] == 'j';
//         ch += s[i] == 'h';
//       }
//       if (cj == m && ch == n) {
//         std::cout << "Yes\n";
//         return;
//       }
//     }
//   }
//   for (int l = 0; l <= s.size(); l++) {
//     for (int r = 0; r <= s.size(); r++) {
//       int cj = 0, ch = 0;
//       for (int i = l; i < s.size(); i++) {
//         cj += s[i] == 'j';
//         ch += s[i] == 'h';
//       }
//       for (int i = 0; i < r; i++) {
//         cj += s[i] == 'j';
//         ch += s[i] == 'h';
//       }
//       if (m >= cj && n >= ch && (m - cj) % 7 == 0 && (n - ch) % 5 == 0) {
//         std::cout << "Yes\n";
//         return;
//       }
//     }
//   }
//   std::cout << "No\n";
// }

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}