#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 1, n = 2e5 - 1;
  std::cout << t << '\n';
  while (t--) {
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << char(rd() % 26 + 'a');
    }
    std::cout << '\n';
  }

  return 0;
}