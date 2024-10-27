#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  for (int i : a) {
    std::cout << i << '\n';
  }
}