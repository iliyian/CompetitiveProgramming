#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937_64 rd(std::random_device{}());

  int t = 10;
  std::cout << t << '\n';
  while (t--) {
    int n = 400;
    std::cout << n << '\n';
    std::vector<int> p(n);
    std::ranges::iota(p, 1);
    std::shuffle(p.begin(), p.end(), rd);
    for (int i : p) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}