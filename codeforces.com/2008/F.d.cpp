#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int n = 2e5, t = 1;
  std::cout << t << '\n';
  while (t--) {
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % (int)1e9 << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}