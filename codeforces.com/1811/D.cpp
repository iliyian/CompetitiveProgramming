// date: 2024-07-13 21:02:13
// tag: 构造

#include <bits/stdc++.h>
#define int long long
// using namespace std;

std::vector<int> fib(46);

bool check(int n, int x, int y) {
  if (n == 1) {
    return true;
  }
  if (fib[n] >= y && y >= fib[n + 1] - fib[n] + 1) return false;
  if (y > fib[n]) return check(n - 1, y - fib[n], x);
  return check(n - 1, y, x);
}

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::cout << (check(n, x, y) ? "YES" : "NO") << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  fib[0] = fib[1] = 1;
  for (int i = 2; i <= 45; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}