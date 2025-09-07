#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 4;
  std::cout << t << '\n';
  while (t--) {
    int n = 5e5, m = 5e5, c = 100;
    std::cout << n << ' ' << m << ' ' << c << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % (m + 1) << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}