#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 1e6, k = 26;
  std::cout << n << ' ' << k << '\n';
  for (int i = 0; i < n; i++) {
    // std::cout << char(rd() % k + 'a')
    std::cout << char(i % 26 + 'a');
  }
  std::cout << '\n';
  // int q = 10;
  int q = 100;
  std::cout << q << '\n';
  while (q--) {
    // int len = rd() % 10 + 1;
    int len = 1e6 / 100;
    for (int i = 0; i < len; i++) {
      // std::cout << char(rd() % (k - 1) + 'a');
      std::cout << char(i % 26 + 'a');
    }
    std::cout << '\n';
  }

  return 0;
}