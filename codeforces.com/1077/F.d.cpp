#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int N = 1e9;
  int n = 1e3, k = 1e2, m = 1e2;
  std::cout << n << ' ' << k << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << rd() % N + 1 << ' ';
  }
  std::cout << '\n';

  return 0;
}