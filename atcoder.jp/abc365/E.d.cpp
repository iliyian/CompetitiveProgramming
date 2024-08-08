#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int n = 2e5, N = 1e8;
  std::cout << n << '\n';
  while (n--) {
    std::cout << rd() % N + 1 << ' ';
  }
  std::cout << '\n';

  return 0;
}