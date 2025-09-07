#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 500;
  std::cout << t << '\n';
  while (t--) {
    int n = 3, w = 10;
    std::cout << n << '\n';
    for (int i = 0; i < n; i++) {
      int l = rd() % w, r = rd() % w;
      if (l > r) std::swap(l, r);
      std::cout << l << ' ' << r << '\n';
    }
  }

  return 0;
}