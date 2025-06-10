#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    int n = (int)2e5 / t, m = (int)3e5 / t;
    std::cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << rd() % (int)1e9 << ' ';
    }
  }

  return 0;
}