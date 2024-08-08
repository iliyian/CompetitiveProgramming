#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  std::string str;
  std::cin >> str;
  for (int i = 1; i < str.size(); i++) {
    if (str[i] == str[i - 1]) {
      str.insert(str.begin() + i, str[i] == 'a' ? 'b' : 'a');
      std::cout << str << '\n';
      return;
    }
  }
  std::cout << (str.front() == 'a' ? 'b' : 'a') << str << '\n';
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