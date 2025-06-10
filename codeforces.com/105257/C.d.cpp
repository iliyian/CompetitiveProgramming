#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 6;
  std::cout << n * 2 << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << (rd() % (n * 2)) + 1 << ' ';
  }

  return 0;
}