#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("d.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int sum = 0;
  for (int i = 1; i <= 8; i++) {
    for (int k = 0; k <= i * (i - 2) / 2; k++) {
      // std::cout << i << ' ' << k << '\n';
      sum++;
    }
  }
  std::cout << sum << '\n';
  for (int i = 1; i <= 8; i++) {
    for (int k = 0; k <= i * (i - 2) / 2; k++) {
      std::cout << i << ' ' << k << '\n';
      // sum++;
    }
  }

  return 0;
}