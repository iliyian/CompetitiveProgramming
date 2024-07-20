#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int n = 2e5, m = 2e5;
  if (argc > 1) n = atoi(argv[1]);
  if (argc > 2) m = atoi(argv[2]);

  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= m; i++) {
    std::cout << rd() % n + 1 << ' ' << rd() % n + 1 << '\n';
  }

  return 0;
}