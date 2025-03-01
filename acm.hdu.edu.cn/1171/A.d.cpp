#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 20;
  std::cout << t << '\n';
  while (t--) {
    int n = 1000, A = rd() % 31 + 2, x = 1023;
    std::cout << n << ' ' << A << ' ' << x << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % 1024 << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}