#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937_64 rd(std::random_device{}());

  int t = 1, v = (int)1e9;
  std::cout << t << '\n';
  while (t--) {
    int n = 420;
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % v + 1 << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}