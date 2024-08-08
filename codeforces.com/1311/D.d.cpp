#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 100, N = 1e4;
  std::cout << t << '\n';
  while (t--) {
    int z = std::uniform_int_distribution<int>{3, N}(rd);
    int y = std::uniform_int_distribution<int>{2, z}(rd);
    int x = std::uniform_int_distribution<int>{1, y}(rd);
    std::cout << x << ' ' << y << ' ' << z << '\n';
  }

  return 0;
}