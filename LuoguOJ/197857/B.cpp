#include <bits/stdc++.h>

int main() {
  freopen("B.in", "r", stdin);
  int t, d, t1, d1, t2, d2;
  std::cin >> t >> d >> t1 >> d1 >> t2 >> d2;
  int ans = INT_MAX;
  if (d <= d1)
    ans = std::min(ans, std::max(0, t1 - t));
  if (d <= d2)
    ans = std::min(ans, std::max(0, t2 - t));
  std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
  return 0;
}