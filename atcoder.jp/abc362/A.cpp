#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int r, g, b;
  std::string c;
  std::cin >> r >> g >> b >> c;

  if (c == "Red") {
    std::cout << std::min(g, b) << '\n';
  }
  if (c == "Green") {
    std::cout << std::min(r, b) << '\n';
  }
  if (c == "Blue") {
    std::cout << std::min(g, r) << '\n';
  }

  return 0;
}