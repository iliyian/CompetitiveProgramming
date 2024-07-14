#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int x1, y1, x2, y2, x3, y3;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  auto check = [](int a, int b, int c) {
    return a + b == c || a + c == b || a == b + c;
  };

  auto dis = [](int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  };

  int a = dis(x2, y2, x3, y3);
  int b = dis(x1, y1, x3, y3);
  int c = dis(x1, y1, x2, y2);
  if (check(a, b, c)) {
    std::cout << "Yes\n";
   } else {
    std::cout << "No\n";
   }

  return 0;
}