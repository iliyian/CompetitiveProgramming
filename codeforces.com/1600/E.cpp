// date: 2024-07-16 09:40:00
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  a[n + 1] = a[0] = INT_MIN;
  if (n == 1) {
    std::cout << "Alice\n";
  } else {

  for (int i = 2; i <= n + 1; i++) {
    if (a[i] <= a[i - 1]) {
      for (int j = n - 1; j >= 0; j--) {\
        if (a[j] <= a[j + 1]) {
          if (i & 1 ^ 1 || (n - j) & 1) {
            std::cout << "Alice\n";
          } else {
            std::cout << "Bob\n";
          }
          return 0;
        }
      }
    }
  }}

  return 0;
}