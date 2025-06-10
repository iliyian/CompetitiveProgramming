#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("data.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 10;
  std::cout << t << '\n';
  while (t--) {
    int n = 20, q = 10;
    std::cout << n << ' ' << q << '\n';
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      int data = std::uniform_int_distribution<>{-1000, 1000}(rd);
      while (data == 0) {
        data = std::uniform_int_distribution<>{-1000, 1000}(rd);
      }
      std::cout << data << ' ';
    }
    std::cout << '\n';
    while (q--) {
      int l = rd() % n + 1, r = rd() % n + 1;
      if (l > r) std::swap(l, r);
      std::cout << l << ' ' << r << '\n';
    }
  }

  return 0;
}