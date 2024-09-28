#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::array<int, 2>>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int l, b;
    std::cin >> l >> b;
    a[b].push_back({l, i});
  }
  std::vector<int> ans(n + 1);
  for (int i = 0; i <= n; i++) {
    std::sort(a[i].begin(), a[i].end());
    for (auto &[l, id] : a[i]) {
      
    }
  }
}