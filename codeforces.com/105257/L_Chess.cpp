#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
}

int get(int x, int k) {
  int ans = 1;
  while (x) {
    ans *= x % k;
    x /= k;
  }
  return ans;
}

bool win(int x, int k) {
  if (!x) return false;
  for (int i = 1; i <= x; i++) {
    int g = get(i, k);
    if (g != 0 && i % g == 0 && !win(x - i, k)) {
      return true;
    }
  }
  return false;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n = 34;
  for (int i = 2; i <= n; i += 2) {
    for (int k = 2;; k++) {
      if (win(i, k)) {
        std::cout << i << ' ' << k << '\n';
        break;
      }
    }
  }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}