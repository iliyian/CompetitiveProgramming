#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 100;
  if (argc > 1) t = atoi(argv[1]);
  int N = 1e5;
  while (t--) {
    int n = std::uniform_int_distribution<int>{3,9}(rd);
    std::cout << n << ' ';
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      a[i] = std::uniform_int_distribution<int>{0,N}(rd);
    }
    for (int l = 1; l <= n; l++) {
      for (int r = l + 1; r <= n; r++) {
        std::cout << a[l] + a[r] << ' ';
      }
    }
    std::cout << '\n';
  }

  return 0;
}