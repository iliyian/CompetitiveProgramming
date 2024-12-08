#include <iostream>
#define int long long

using namespace std;

// 1 * 3 + 1 = 4
// 4 * 1.5 + 1 = 7
// 7 * 1.5 + 1 = 11.5

// 3 * 3 + 1 = 10
// 10 * 1.5 + 1 = 16
// 6 * 1

signed main() {
  int n, i;
  cin >> n >> i;
  if (n == 1) {
    std::cout << 1 << '\n';
    return 0;
  }
  for (int j = 1;; j++) {
    int cur = j * n + 1;
    bool f = true;
    for (int k = 1; k <= n - 1; k++) {
      if (cur % (n - 1)) {
        f = false;
        break;
      }
      cur = cur / (n - 1) * n + i;
    }
    if (f) {
      std::cout << cur << '\n';
      return 0;
    }
  }
  return 0;
}