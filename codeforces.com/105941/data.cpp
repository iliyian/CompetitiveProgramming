#include <bits/stdc++.h>
#include <random>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  std::ofstream os("d.in");
  int t = 1000;
  os << t << '\n';
  while (t--) {
    int n = 10, l = -10, r = 10;
    os << n << '\n';
    int w = (r - l + 1);
    auto gen = [&]() {
      return rd() % w + l;
    };
    for (int i = 1; i <= n; i++) {
      os << gen() << ' ' << gen() << '\n';
    }
  }

  return 0;
}