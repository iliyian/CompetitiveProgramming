#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int N = 1e5;
  int t = 1;

  int n = N / t;
  std::cout << t << '\n';
  while (t--) {
    std::cout << n << '\n';
    std::vector<int> a(n + 1);
    std::iota(a.begin() + 1, a.end(), 1);
    std::shuffle(a.begin() + 1, a.end(), rd);
    for (int i = 1; i <= n; i++) {
      std::cout << a[i] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}