// date: 2024-08-01 18:54:48
// tag: 构造

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::string str;
  std::cin >> str;

  bool f = false;
  std::string x(str.size(), '0'), y(str.size(), '0');
  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] != 'Z') {
      f = true;
    } else {
      if (f) {
        std::cout << -1 << '\n';
        return 0;
      }
    }
    if (str[i] == 'X') x[i] = '1';
    else if (str[i] == 'Y') y[i] = '1';
  }
  std::cout << x << '\n' << y << '\n';


  return 0;
}