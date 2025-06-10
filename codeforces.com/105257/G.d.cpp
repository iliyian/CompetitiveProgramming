#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 100;
  std::cout << t << '\n';
  int n = 1, x = 1;
  while (t--) {
    std::cout << n << ' ' << x << '\n';
    x++;
    auto check = [&](int c) {
      while (c) {
        if (c % 10 == x) return true;
        c /= 10;
      }
      return false;
    };
    if (x == 10) {
      x = 1;
    }
    n++;
    while (check(n)) n++;
  }

  return 0;
}