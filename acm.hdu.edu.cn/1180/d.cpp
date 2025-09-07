#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    int n = 20, w = 3;
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % w << ' ';
    }
    std::cout << '\n';
    std::vector<std::set<int>> s(n + 1);
    int cnt = n;
    for (int i = 1; i <= n; i++) {
      int h = rd() % cnt + 1;
      std::cout << h << ' ';
      for (int j = 1; j <= h; j++) {
        int x;
        while (1) {
          x = rd() % n + 1;
          if (s[i].count(x)) continue;
          s[i].insert(x);
          break;
        }
      }
    }
    std::cout << '\n';
    for (int i = 1; i <= n; i++) {
      for (auto j : s[i]) {
        std::cout << j << ' ';
      }
      std::cout << '\n';
    }
  }

  return 0;
}