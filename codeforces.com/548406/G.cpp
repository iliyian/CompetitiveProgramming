#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  for (int a = 1; a <= 100; a++) {
    if (a % 3 == 0) continue;
    for (int b = 1; b <= 100; b++) {
      if (b == a || b % 3 == 0) continue;
      int c = n - a - b;
      if (c > 0 && c != a && c != b && c % 3) {
        std::cout << "YES\n";
        std::cout << a << ' ' << b << ' ' << c << '\n';
        return;
      }
    }
  }
  std::cout << "NO\n";
  return;
  if (n % 3 == 0) {
    if (n < 12) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      std::cout << 1 << ' ' << 4 << ' ' << n - 5 << '\n';
    }
  } else if (n % 3 == 1) {
    if (n < 10) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      std::cout << 1 << ' ' << 4 << ' ' << n - 5 << '\n';
    }
  } else {
    if (n < 8) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      std::cout << 1 << ' ' << 2 << ' ' << n - 3 << '\n';
    }
  }
}

signed main() {
  freopen("G.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}