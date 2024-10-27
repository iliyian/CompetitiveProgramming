#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 998244353;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("2.in", "r", stdin);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), fac(n + 1);
  std::vector<int> c(1e6 + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    c[a[i]]++;
  }
  std::sort(a.begin() + 1, a.end());
  int mn = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      mn += a[j] - a[i];
    }
  }
  a.erase(std::unique(a.begin() + 1, a.end()), a.end());
  int ans = (a.size() == 2 ? 1 : 2);
  for (int i = 1; i < a.size(); i++) {
    ans = ans * fac[c[a[i]]] % mod;
  }
  std::cout << mn << ' ' << ans << '\n';
  return 0;
}