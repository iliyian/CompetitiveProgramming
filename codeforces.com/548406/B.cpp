#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y;
  std::cin >> x >> y;
  std::cout << (23 - x) * 60 + 60 - y << '\n';
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}