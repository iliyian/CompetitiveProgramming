#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n;
  std::cin >> n;
  std::cout << ((n % 4 == 0 && n % 100) || n % 400 == 0 ? 366 : 365) << '\n';

  return 0;
}