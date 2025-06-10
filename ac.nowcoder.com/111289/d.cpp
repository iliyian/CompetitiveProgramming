#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 100;
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    int x = std::uniform_int_distribution<>{(int)-1e5, (int)1e5}(rd);
    std::cout << x << " \n"[i == n];
  }
  for (int i = 1; i <= n; i++) {
    int r = rd() % (int)1e5 + 1;
    std::cout << r << " \n"[i == n];
  }

  return 0;
}