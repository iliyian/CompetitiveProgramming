#include <bits/stdc++.h>
#include <random>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int n = 1e4;
  std::cout << 1 << '\n';
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << (rd() % (int)1e8) * 10 << ' ';
  }
  std::cout << '\n';

  return 0;
}