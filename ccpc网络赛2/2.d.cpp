#include <bits/stdc++.h>
using namespace std;

std::mt19937 rd(std::random_device{}());

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("2.in", "w", stdout);
  int n = 1000;
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << (int)(1e6) - 10 << ' ';
  }
  std::cout << '\n';
}