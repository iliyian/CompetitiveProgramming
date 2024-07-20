#include <bits/stdc++.h>
// #define int long long
// using namespace std;

signed main(int argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "w", stdout);
  
  std::mt19937 rd(std::random_device{}());

  int N = 2e5, mod = 1e9;
  if (argc > 1) N = atoi(argv[1]);
  if (argc > 2) mod = atoi(argv[2]);

  std::cout << N << '\n';
  for (int i = 1; i <= N; i++) {
    std::cout << std::min(i, N - i + 1) << ' ';
  }

  return 0;
}