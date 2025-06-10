#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1000;
  std::cout << t << '\n';
  while (t--) {
    int n = rd() % (int)(1e6) + 1;
    int k = rd() % (20) + 1;
    std::cout << n << ' ' << k << '\n';
  }

  return 0;
}