#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n, s;
  std::cin >> n >> s;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    sum += x;
  }
  std::cout << n - (sum != s);

  return 0;
}