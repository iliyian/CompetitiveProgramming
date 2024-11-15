// date: 2024-11-14 22:40:53
// tag: 

#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;

int idx(int x) {
  return (x - 1 + n) % n + 1;
}

void solve() {
  std::cin >> n;
  std::vector<int> a(n + 1), ans(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  a[0] = a[n];
  for (int i = 1; i <= n; i++) {
    b[i] = a[i] - a[i - 1];
  }
  std::vector<int> odd(n + 2), even(n + 2);
  auto add = [&](int l, int r, std::vector<int> &which, int v) {
    if (l > r) return;
    which[l] += v;
    which[r + 1] -= v;
  };
  auto modify = [&](int x, int v) -> void {
    if (x & 1) {
      add(1, x - 1, even, v);
      add(x + 2, n, odd, v);
    } else {
      add(1, x - 1, odd, v);
      add(x + 2, n, even, v);
    }
  };
  for (int i = 1; i <= n * 3; i++) {
    int x = idx(i), y = idx(i + 2);
    if (b[x] > 0) {
      modify(x, b[x]);
      b[y] += b[x];
      b[x] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    odd[i] += odd[i - 1];
    even[i] += even[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    std::cout << (i & 1 ? odd[i] : even[i]) << " \n"[i == n];
  }
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