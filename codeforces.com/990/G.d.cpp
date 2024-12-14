#include "tree.h"
#include <bits/stdc++.h>
using namespace std;
using namespace tree_generator_by_ouuan;

std::mt19937 rd(std::random_device{}());

int main(int argc, char **argv) {
  if (argc < 2) return 1;
  int n = atoi(argv[1]);
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << 2 << ' ';
  }
  std::cout << '\n';
  Tree t(n);
  std::cout << t << '\n';
  return 0;
}