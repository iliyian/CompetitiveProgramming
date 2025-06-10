#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1000;
  std::cout << t << '\n';
  while (t--) {
    int n = 1000;
    int siz = 0;
    std::cout << n << '\n';
    for (int i = 2; i <= n; i++) {
      std::cout << rd() % (i - 1) + 1 << ' ' << i << ' ' << rd() % n << '\n';
    }
  }

  return 0;
}