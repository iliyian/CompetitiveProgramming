#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1;
  // std::cout << t << '\n';
  while (t--) {
    int N = 5e5;
    int n = N, q = N;
    std::cout << n << ' ' << q << ' \n';
    std::vector<std::vector<int>> a(n + 1,)
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        std::cout << char(rd() % 2 || j == 1 || j == m ? '0' : '1');
      }
      std::cout << '\n';
    }
  }

  return 0;
}