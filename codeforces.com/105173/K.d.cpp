#include <bits/stdc++.h>

std::mt19937 rd(std::random_device{}());

int main(int argc, char **argv) {
  freopen("K.in", "w", stdout);
  int n = 3;
  if (argc > 1) n = atoi(argv[1]);
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << rd() % (int)1e3 + 1 << ' ' << rd() % 2 << '\n';
  }
}