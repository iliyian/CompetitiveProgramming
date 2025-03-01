#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("K.old.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int n = 30, m = 100;
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << 1 << ' ';
  }
  std::cout << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << 1 << ' ';
  }
  std::cout << '\n';

  return 0;
}