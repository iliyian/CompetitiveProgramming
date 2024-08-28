#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int n = 5000;
  if (argc > 1) n = atoi(argv[1]);
  std::cout << n << '\n';

  std::vector<std::vector<int>> a(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      a[i][j] = rd() % 2;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      a[i][j] = a[j][i] ^ 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << a[i][j];
    }
    std::cout << '\n';
  }

  return 0;
}