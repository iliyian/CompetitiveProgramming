#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int N = 1e5;
  int n = N, q = N;
  if (argc > 1) n = atoi(argv[1]);
  if (argc > 2) q = atoi(argv[2]);
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << rd() % n + 1 << ' ';
  }
  std::cout << '\n' << q << '\n';
  for (int i = 1; i <= q; i++) {
    std::cout << rd() % n + 1 << ' ' << rd() % n + 1 << '\n';
  }

  return 0;
}