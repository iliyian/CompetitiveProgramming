#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    int n = 5000;
    std::cout << n << ' ' << rd() % (n * (n + 1) / 2) + 1 << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % (int)(1e9) + 1 << ' ';
    }
    std::cout << '\n';
  }


  return 0;
}