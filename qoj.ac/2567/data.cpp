#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("d.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 1680000;
  std::cout << t << '\n';
  for (int a = 0; a <= 200; a++) {
    for (int b = 0; b <= 200; b++) {
      for (int n = 0; n <= 21; n++) {
        for (int p = 0; p <= 1; p++) {
          std::cout << a << ' ' << b << ' ' << n << ' ' << p << '\n';
        }
      }
    }
  }

  return 0;
}