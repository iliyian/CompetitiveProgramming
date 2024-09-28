#include <bits/stdc++.h>
#include <random>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 5e5, m = 5e5, N = 2;
  int maxq = 0;
  bool largequery = false, largemodify = false;
  if (argc > 1) {
    if (std::string(argv[1]) == "largequery") {
      largequery = true;
    }
    if (std::string(argv[1]) == "largemodify") {
      largemodify = true;
    }
  }
  if (!largemodify && !largequery) {
    if (argc > 1) n = atoi(argv[1]);
    if (argc > 2) m = atoi(argv[2]);
    if (argc > 3) N = atoi(argv[3]);
    if (argc > 4) maxq = atoi(argv[4]);
  }
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    if (largemodify || largequery) {
      if (i == 1 && largequery) {
        std::cout << 0 << ' ';
      } else {
        std::cout << (i & 1) << ' ';
      }
    } else {
      std::cout << rd() % N << ' ';
    }
  }
  std::cout << '\n';
  for (int i = 1; i <= m; i++) {
    if (largemodify) {
      std::cout << rd() % 3 + 1 << ' ' << 1 << ' ' << n << ' ' << (i & 1) << '\n';
    } else if (largequery) {
      std::cout << 4 << ' ' << (1 + i % 2) << ' ' << n << '\n';
    } else {
      int op = rd() % 4 + 1;
      // if (i < m) op = rd() % 3 + 1;
      // else op = 4;
      int l = rd() % n + 1, r = rd() % n + 1;
      if (l > r) std::swap(l, r);
      if (op == 4 && maxq) {
        r = l + rd() % maxq;
        r = std::min(r, n);
      }
      std::cout << op << ' ' << l << ' ' << r << ' ';
      if (op != 4) {
        if (op == 1 || op == 3) {
          std::cout << 1 << ' ';
        } else if (op == 2) {
          std::cout << 0 << ' ';
        }
        // std::cout << rd() % N << ' ';
      }
      std::cout << '\n';
    }
  }

  return 0;
}