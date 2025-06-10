#include <bits/stdc++.h>
#include <random>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 500, m = 500, s = rd() % n + 1, t = rd() % n + 1;
  std::cout << n << ' ' << m << ' ' << s << ' ' << t << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cout << std::uniform_int_distribution<>{(int)-5e4, (int)5e4}(rd) << " \n"[j == m];
    }
  }

  return 0;
}