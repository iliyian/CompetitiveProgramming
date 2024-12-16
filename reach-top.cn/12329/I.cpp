#include <algorithm>
#include <bits/stdc++.h>
#define int long long

int calc(int x) {
  int ans = 0;
  while (x)
    ans += x % 10, x /= 10;
  return ans;
}

std::string rev(std::string str) {
  std::reverse(str.begin(), str.end());
  return str;
}

bool isprime(int x) {
  if (x < 2)
    return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int a[34][34] = {0};
void solve() {
  for (int i = 0; i < 34; i++) {
    a[i][0] = a[i][i] = 1;
    for (int j = 1; j <= i; j++)
      a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
  }
  int m, n;
  while (std::cin >> m >> n)
    std::cout << a[m][n] << std::endl;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}