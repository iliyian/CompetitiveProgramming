#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("d.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 100;
  std::cout << t << '\n';
  while (t--) {
    int l = rd() % 100 + 2, r = rd() % 100 + 2;
    while (l % 3 != r % 3) {
      l = rd() % 100 + 2, r = rd() % 100 + 2;
      if (l > r) std::swap(l, r);
    }
    std::cout << l << ' ' << r << '\n';
  }

  return 0;
}