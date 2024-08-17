#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  std::string str;
  std::cin >> str;
  if (str.size() >= 3 && str.substr(0, 2) == "10" && str[2] != '0' && std::stoi(str.substr(2, str.size() - 2 + 1)) >= 2) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
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