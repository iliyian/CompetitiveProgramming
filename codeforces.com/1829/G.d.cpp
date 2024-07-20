#include <bits/stdc++.h>
#include <random>
#define int long long
// using namespace std;

signed main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 1000, N = 1e6;

  std::cout << t << '\n';
  for (int i = 1; i <= t; i++) {
    std::cout << std::uniform_int_distribution<int>{(int)(N), N}(rd) << '\n';
  }

  return 0;
}