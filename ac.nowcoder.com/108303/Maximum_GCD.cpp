#include <bits/stdc++.h>
// #define int long long
using namespace std;

constexpr int N = 1e5;
std::vector<std::vector<int>> fac(N + 1);

int gcd(int a, int b) {
  if (!a | !b)
    return a + b;
  int az = __builtin_ctz(a);
  int bz = __builtin_ctz(b);
  int z = min(az, bz);
  a >>= az, b >>= bz;
  while (a != b) {
    int diff = b - a;
    az = __builtin_ctz(diff);
    b = min(a, b), a = abs(diff) >> az;
  }
  return a << z;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1), v;
  int ans = 0;
  bool f = true;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (i > 1 && a[i] != a[i - 1]) {
      f = false;
    }
    b[i] = std::abs(a[i] - a[i - 1]);
    ans = gcd(ans, b[i]);
    for (int j : fac[a[i]]) {
      // s.insert(j);
      v.push_back(j);
    }
    for (int j : fac[b[i]]) {
      // s.insert(j);
      v.push_back(j);
    }
  }
  if (f) {
    std::cout << 0 << '\n';
    return;
  }
  std::ranges::sort(v);
  // v.erase(std::unique)
  int pre = 0;
  for (int g : v) {
    if (g == pre) continue;
    pre = g;
    int cnt = 0, last = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i] % g) {
        if (last != i - 1 || b[i] % g) {
          cnt++;
          if (cnt >= 2) {
            break;
          }
        }
        last = i;
      }
    }
    if (cnt == 1 || cnt == 0) {
      ans = std::max(ans, g);
    }
  }
  std::cout << ans << "\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}