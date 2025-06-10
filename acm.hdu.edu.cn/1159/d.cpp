#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 100;
  std::cout << t << '\n';
  while (t--) {
    int n = (int)1e5;
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % (int)1e6 + 1 << ' ';
      // std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}