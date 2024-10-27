#include <bits/stdc++.h>
#include <cctype>

int main() {
  std::string str;
  std::cin >> str;
  int ans = 0;
  std::set<char> s;
  for (char i : str) {
    if (islower(i)) {
      s.insert(i);
    }
  }
  std::cout << s.size() << '\n';
  return 0;
}