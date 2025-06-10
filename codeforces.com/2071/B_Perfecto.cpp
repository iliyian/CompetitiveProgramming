#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << -1 << '\n';
    return;
  }
  int sum = n * (n + 1) / 2;
  int x = sqrtl(sum);
  if (x * x == sum) {
    std::cout << -1 << '\n';
    return;
  }
  std::vector<int> p(n + 1);
  std::iota(p.begin() + 1, p.end(), 1);
  while (1) {
    int sum = 0;
    std::shuffle(p.begin() + 1, p.end(), rd);
    bool f = true;
    for (int i = 1; i <= n; i++) {
      sum += p[i];
      int x = sqrtl(sum);
      if (x * x == sum) {
        f = false;
        break;
      }
    }
    if (f) {
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << p[i] << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // int sum = 3;
  // int N = 5e5, sum = 0;
  // // for (int i = 3; i <= N; i++) {
  // for (int i = N; i >= 1; i--) {
  //   sum += i;
  //   int x = sqrtl(sum);
  //   if (x * x == sum) {
  //     std::cout << i << ' ' << x << ' ' << sum << '\n';
  //     // return 0;
  //   }
  // }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}