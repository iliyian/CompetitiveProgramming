#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 50, q = 1e5;
  std::cout << n << ' ' << q << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      std::cout << char(rd() % 2 + '0');
    }
    std::cout << '\n';
  }
  while (q--) {
    int x = rd() % n + 1, y = rd() % n + 1;
    while (x == y) {
      x = rd() % n + 1, y = rd() % n + 1;
    }
    std::cout << x << ' ' << y << '\n';
  }

  return 0;
}