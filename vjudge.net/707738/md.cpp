#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937_64 rd(std::random_device{}());

  int t = 20;
  std::cout << t << '\n';
  while (t--) {
    int n = rd() % (int)1e9, m = rd() % (int)1e4;
    std::cout << n << ' ' << m << '\n';
  }

  return 0;
}