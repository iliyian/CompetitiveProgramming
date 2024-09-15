#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  if (n == 3) {
    std::cout << "1 -10 6 6 -10 1\n";
    return;
  }
  std::cout << 1 << ' ' << 2 << ' ';
  for (int i = 2; i <= n - 1; i++) {
    std::cout << -1 << ' ' << 2 << ' ';
  }
  std::cout << -1 << ' ' << 3 - n << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("D.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}