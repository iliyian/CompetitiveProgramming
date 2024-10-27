#include <bits/stdc++.h>
#include <cctype>

int main() {
  std::string a, b;
  getline(std::cin, a);
  getline(std::cin, b);
  for (char &c : a) {
    if (isupper(c)) {
      c = tolower(c);
    }
  }
  for (char &c : b) {
    if (isupper(c)) {
      c = tolower(c);
    }
  }
  std::cout << (a < b ? '<' : a == b ? '=' : '>') << '\n';
  return 0;
}