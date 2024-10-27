#include <bits/stdc++.h>

int main() {
  std::vector<int> a;
  int x;
  while (std::cin >> x) {
    a.push_back(x);
  }
  for (int i = 0; i < a.size() / 2; i++) {
    std::cout << std::setw(5) << a[i] + a[i + a.size() / 2];
  }
  return 0;
}
