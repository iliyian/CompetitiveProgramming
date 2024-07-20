#include <bits/stdc++.h>
#include <random>
#define int long long
// using namespace std;

signed main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "w", stdout);

  std::mt19937 mt(std::random_device{}());

  int t = 1;
  std::cout << t << '\n';

  int n = 2e5, w = 1e9, sum = 0;
  if (argc > 1) w = atoi(argv[1]);
  if (argc > 2) n = atoi(argv[2]);
  
  int prv = 0;
  std::vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    std::uniform_int_distribution<int> x(prv + 1, w / n * i);
    l[i] = x(mt);

    std::uniform_int_distribution<int> y(l[i], w / n * i);
    r[i] = y(mt);

    prv = r[i] + 1;
    sum += r[i] - l[i] + 1;
  }
  
  std::cout << n << ' ' << std::uniform_int_distribution<int>{1, sum}(mt) << '\n';
  
  for (int i = 1; i <= n; i++) {
    std::cout << l[i] << ' ';
  }
  std::cout << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << r[i] << ' ';
  }


  return 0;
}