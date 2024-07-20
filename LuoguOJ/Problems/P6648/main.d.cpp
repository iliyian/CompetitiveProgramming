#include <bits/stdc++.h>
// using namespace std;

std::mt19937 rd(std::random_device{}());

signed main(int argc, char **args) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "w", stdout);

  int n = atoi(args[1]), k = atoi(args[2]);
  int mod = (argc < 4 ? int(1e9) : atoi(args[3]));

  std::cout << n << ' ' << k << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      std::cout << rd() % mod << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}