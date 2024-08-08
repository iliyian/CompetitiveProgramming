#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int n = 1e4, k = 20, N = 1e9;
  std::cout << n << ' ' << k << '\n';
  for (int i = 1; i <= n; i++) {
    int x, r, q;
    std::cout << (rd() % N) << ' ' << (rd() % N) << ' ' << (rd() % 100) << '\n';
  }

  return 0;
}