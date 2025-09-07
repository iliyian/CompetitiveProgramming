#include <bits/stdc++.h>
#define int long long

void solve() {
  int n1, n2;
  std::cin >> n1 >> n2;
  std::vector<std::array<int, 5>> a(n1 + 1), b(n2 + 1);
  for (int i = 1; i <= n1; i++) {
    for (int j = 0; j < 5; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n2; i++) {
    for (int j = 0; j < 4; j++) {
      std::cin >> b[i][j];
    }
  }
  bool f = false;
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      std::set<int> s;
      for (int k = 0; k < 5; k++) {
        s.insert(a[i][k]);
      }
      for (int k = 0; k < 4; k++) {
        s.insert(b[j][k]);
      }
      if (s.size() == 9) {
        std::cout << i << ' ' << j << '\n';
        f = true;
      }
    }
  }
  if (!f) {
    std::cout << "None\n";
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}