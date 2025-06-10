#include <bits/stdc++.h>
#include <random>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 100;
  std::cout << t << '\n';;
  int w = 1e4;
  while (t--) {
    int a = std::uniform_int_distribution<long long>{1, w}(rd);
    int b = std::uniform_int_distribution<long long>{1, w}(rd);
    int c = std::uniform_int_distribution<long long>{1, w}(rd);
    int d = std::uniform_int_distribution<long long>{1, w}(rd);
    std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  }

  return 0;
}