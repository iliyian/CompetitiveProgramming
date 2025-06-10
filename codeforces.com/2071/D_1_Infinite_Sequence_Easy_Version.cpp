#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;

std::vector<int> a(N + 1);
int n, n1;

int sumx(int x);
int getx(int x) {
  if (x <= n) return a[x] ^ a[x - 1];
  return sumx(x / 2);
}

int sumx(int x) {
  if (x <= n) return a[x];
  if (x % 2 == 1) {
    if (n % 2 == 1) return a[n];
    return n1;
  }
  return getx(x) ^ sumx(x - 1);
}

void solve() {
  int l, r;
  std::cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] ^= a[i - 1];
  }
  n1 = 0;
  for (int i = 1; i <= (n + 1) / 2; i++) {
    n1 ^= a[i] ^ a[i - 1];
  }
  n1 ^= a[n];
  // auto getx = [&](auto self, int x) -> int {
  //   if (x <= n) return a[x] ^ a[x - 1];
  //   return sumx(sumx, x / 2);
  // };
  // auto sumx = [&](auto self, int x) -> int {
  //   if (x <= n) return a[x];
  //   if (x % 2 == 1) {
  //     if (n % 2 == 1) return a[n];
  //     return x;
  //   }
  //   return self(self, x - 1) + getx(getx, x);
  // };
  std::cout << getx(l) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}