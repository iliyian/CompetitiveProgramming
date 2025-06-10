#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1000;
  std::cout << t << '\n';
  int w = 1e9;
  while (t--) {
    int n = 300, u = rd() % (w / 5) + 1, k = rd() % (3000) + 1, hq = rd() % w + 1;
    std::cout << n << ' ' << u << ' ' << k << ' ' << hq << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % (w / 20) + 1 << ' ' << rd() % w + 1 << '\n';
    }
  }

  return 0;
}