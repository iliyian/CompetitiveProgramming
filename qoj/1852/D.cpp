#include <bits/stdc++.h>
#define int long long

constexpr int N = 5e5;

std::vector<int> d(N + 1);

void add(int x, int c) {
  for (int i = x; i <= N; i += i & -i) d[i] += c;
}

int query(int x) {
  int ans = 0; for (int i = x; i > 0; i -= i & -i) ans += d[i]; return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  int ac = 0, bc = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    add(a[i], 1);
    ac += i - 1 - query(a[i] - 1);
  }
  for (int i = 1; i <= n; i++) {
    add(a[i], -1);
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    add(b[i], 1);
    bc += i - 1 - query(b[i] - 1);
  }
  for (int i = 1; i <= n; i++) {
    add(b[i], -1);
  }
  ac &= 1, bc &= 1;
  if (ac == bc) {
    std::cout << "B";
  } else {
    std::cout << "A";
  }
  for (int i = 1; i <= n - 1; i++) {
    char t;
    int l, r, p;
    std::cin >> t >> l >> r >> p;
    int len = (r - l + 1);
    p %= len;
    if (t == 'A') ac ^= p * (len - p) & 1;
    else bc ^= p * (len - p) & 1;

    if (ac == bc) {
      std::cout << "B";
    } else {
      std::cout << "A";
    }
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}