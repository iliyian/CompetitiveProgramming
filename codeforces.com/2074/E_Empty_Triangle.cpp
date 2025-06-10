#include <bits/stdc++.h>
#define int long long

int ask(int a, int b, int c) {
  std::cout << "? " << a << ' ' << b << ' ' << c << std::endl;
  int x;
  std::cin >> x;
  return x;
}

void answer(int a, int b, int c) {
  std::cout << "! " << a << ' ' << b << ' ' << c << std::endl;
}

std::mt19937 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  int a[3] = {1, 2, 3};
  for (int i = 1; i <= 75; i++) {
    int x = ask(a[0], a[1], a[2]);
    if (!x) {
      answer(a[0], a[1], a[2]);
      return;
    }
    a[rd() % 3] = x;
  }
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