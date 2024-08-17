#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int x = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    x ^= a[i];
  }
  if (x == 0) {
    std::cout << "lose\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if ((x ^ a[i]) < a[i]) {
      int A = a[i] - (x ^ a[i]);
      std::cout << A << ' ' << i << '\n';
      a[i] -= A;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}