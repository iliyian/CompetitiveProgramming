#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("d.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 10;
  std::cout << t << '\n';
  while (t--) {
    // int n = rd() % 100 + 1;
    int n = 1e5;
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % 10 + 1 << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}