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
    int n = 4, m = 100000;
    for (int i = 0; i < n; i++) {
      std::cout << char(rd() % 26 + 'A');
    }
    std::cout << ' ';
    for (int i = 0; i < m; i++) {
      std::cout << char(rd() % 26 + 'A');
    }
    std::cout << '\n';
  }

  return 0;
}