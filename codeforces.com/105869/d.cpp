#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937_64 rd(std::random_device{}());

  int t = 1e5;
  std::cout << t << '\n';
  auto u = std::uniform_int_distribution<int>{1, (int)1e18};
  while (t--) {
    std::cout << u(rd) << ' ' << u(rd) << '\n';
  }

  return 0;
}