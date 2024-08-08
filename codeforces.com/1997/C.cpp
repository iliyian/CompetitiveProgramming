#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  std::stack<int> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '_') {
      if (!s.empty()) {
        str[i] = ')';
        int u = s.top(); s.pop();
        ans += i - u;
      } else {
        str[i] = '(';
        s.push(i);
      }
    } else if (str[i] == '(') {
      s.push(i);
    } else {
      assert(!s.empty());
      int u = s.top(); s.pop();
      ans += i - u;
    }
  }
  // std::cout << str << '\n' << ans << '\n';
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}