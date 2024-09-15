#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::string str = "aeiou";
  int x = n / 5;
  int y = n - x * 5;
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < (n + 4) / 5; j++) {
      std::cout << str[i];
    }
  }
  for (int i = y; i < 5; i++) {
    for (int j = 0; j < n / 5; j++) {
      std::cout << str[i];
    }
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}