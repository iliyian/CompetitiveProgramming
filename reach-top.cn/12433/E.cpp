#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int fac(int x) {if (!x) return 1; return x * fac(x - 1);}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }
  std::sort(a.begin(), a.end());
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1] + 1) {
      std::cout << a[i - 1] + 1 << '\n';
      return 0;
    }
  }
  std::cout << -1 << '\n';
  return 0;
}