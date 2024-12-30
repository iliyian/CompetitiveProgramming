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

std::vector<std::vector<int>> f(1e3, std::vector<int>(1e3, -1));
int dfs(int x, int lst) {
  if (x == 0) return 1;
  if (lst > x) return 0;
  if (f[x][lst] != -1) return f[x][lst];
  int ans = 0;
  for (int i = lst + 1; i <= x; i++) {
    ans += dfs(x - i, i);
  }
  return f[x][lst] = ans;
}

signed main() {
  // std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::cout << dfs(n, 0) << '\n';
  return 0;
}