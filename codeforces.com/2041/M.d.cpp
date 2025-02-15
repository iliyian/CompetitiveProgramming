#include <bits/stdc++.h>
#define int long long

struct Node {
  int x, id, rnk1, rnk2;
};

int n = 1e6;

std::mt19937 rd(std::random_device{}());
std::vector<int> a;

void solve() {
  std::cout << n << '\n';
}

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  if (argc > 1) n = atoi(argv[1]);
  for (int i = 1; i <= n; i++) t *= i;
  std::cout << t << '\n';
  a.resize(n);
  std::iota(a.begin(), a.end(), 0);
  do {
    std::cout << n << '\n';
    for (auto i : a) {
      std::cout << i + 1 << ' ';
    }
    std::cout << '\n';
  } while (std::next_permutation(a.begin(), a.end()));
  return 0;
}