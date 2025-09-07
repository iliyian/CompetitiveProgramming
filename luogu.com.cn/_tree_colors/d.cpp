#include <bits/stdc++.h>
#include "tree_generator.h"
#define int long long
// using namespace std;

using namespace tree_generator_by_ouuan;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());
  
  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    int n = 10000;
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % n + 1 << " \n"[i == n];
    }
    for (int i = 2; i <= n; i++) {
      std::cout << rd() % (i - 1) + 1 << ' ' << i << '\n';
    }
    // Tree t(n);
    // std::cout << t << '\n';
  }

  return 0;
}