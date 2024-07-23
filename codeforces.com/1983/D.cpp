// date: 2024-07-23 15:49:25
// tag: 逆序对

#include <bits/stdc++.h>
#define int long long
#define N ((int)2e5 + 5)
// using namespace std;

std::vector<int> d(N);

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  auto add = [&](int x, int c) {
    for (int i = x; i < N; i += i & -i) {
      d[i] += c;
    }
  };
  auto sum = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      ans += d[i];
    }
    return ans;
  };

  int cnta = 0, cntb = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    add(a[i], 1);
    cnta += sum(2e5) - sum(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    add(a[i], -1);
  }
  sort(a.begin() + 1, a.end());
  std::vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    add(b[i], 1);
    cntb += sum(2e5) - sum(b[i]);
  }
  for (int i = 1; i <= n; i++) {
    add(b[i], -1);
  }
  sort(b.begin() + 1, b.end());
  if (a != b) {
    std::cout << "NO\n";
    return;
  }
  if ((cnta & 1) == (cntb & 1)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}