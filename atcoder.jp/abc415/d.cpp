#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 5e5, q = 5e5;
  std::cout << n << ' ' << q << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << char(rd() % 26 + 'a');
  }
  std::cout << '\n';
  while (q--) {
    int op = rd() % 2 + 1;
    std::cout << op << '\n';
    if (op == 1) {
      std::cout << rd() % n + 1 << ' ' << char(rd() % 26 + 'a') << ' ';
    } else {
      int l = rd() % n + 1, r = rd() % n + 1;
      if (l > r) std::swap(l, r);
      std::cout << l << ' ' << r << '\n';
    }
  }

  return 0;
}