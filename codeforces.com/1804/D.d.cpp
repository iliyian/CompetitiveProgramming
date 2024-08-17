#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 4;
  if (argc > 1) t = atoi(argv[1]);

  std::cout << (1 << t) << '\n';
  for (int i = 0; i < (1 << t); i++) {
    std::cout << 1 << ' ' << t << '\n';
    for (int j = 0; j < t; j++) {
      std::cout << (i >> j & 1);
    }
    std::cout << '\n';
  }

  return 0;
}