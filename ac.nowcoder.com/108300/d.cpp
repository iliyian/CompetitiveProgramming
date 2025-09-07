#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1000;
  std::cout << t << '\n';
  while (t--) {
    int w = 1ll << 5;
    auto get = [&]() -> int {
      int q = rd() % 10;
      if (q == 0) {
        return 0;
      }
      return rd() % w;
    };
    int a = get(), b = get(), c = get();
    std::cout << a << ' ' << b << ' ' << c << '\n';
  }

  return 0;
}