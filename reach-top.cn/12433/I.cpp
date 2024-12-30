#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int fac(int x) {if (!x) return 1; return x * fac(x - 1);}
bool isprime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      f[i][j] = std::max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
    }
  }
  int mx = 0;
  for (int i = 1; i <= n; i++) mx = std::max(mx, f[n][i]);
  std::cout << mx << '\n';
  return 0;
}