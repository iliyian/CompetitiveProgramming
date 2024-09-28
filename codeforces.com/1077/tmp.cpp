#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("tmp.in", "r", stdin);
  freopen("tmp.out", "w", stdout);

  int a, b, c;
  std::cin >> a >> b >> c;
  std::vector<std::vector<char>> ans(2 * c + 1 + 2 * b + 1, std::vector<char>(a * 2 + 1 + b * 2 + 1, '.'));
  

  return 0;
}