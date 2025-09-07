#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    int n = 3000;
    std::cout << n << '\n';
    for (int i = 0; i < n; i++) {
      std::cout << char(rd() % 17 + 'a');
    }
    std::cout << '\n';
    for (int i = 0; i < 17; i++) {
      std::cout << rd() % (int)1e6 << ' ';
    }
    std::cout << '\n';
    std::cout << rd() % 10 + 1 << '\n';
  }

  return 0;
}