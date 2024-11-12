#include <bits/stdc++.h>
#define int long long

void solve() {
  int a[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    int sum = 0;
    for (int j = 0; j < 3; j++) {
      sum += a[i][j];
    }
    if (sum != 15) {
      std::cout << "OMyGa!\n";
      return;
    }
  }
  for (int j = 0; j < 3; j++) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
      sum += a[i][j];
    }
    if (sum != 15) {
      std::cout << "OMyGa!\n";
      return;
    }
  }
  if (a[0][0] + a[1][1] + a[2][2] != 15 || a[2][0] + a[1][1] + a[0][2] != 15) {
    std::cout << "OMyGa!\n";
    return;
  }
  std::cout << "Cheers!\n";
}

signed main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}