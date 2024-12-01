#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

bool ispalin(int n) {
  std::string s = std::to_string(n);
  std::string t = s; std::reverse(s.begin(), s.end());
  return s == t;
}

int main() {
  int n = 0;
  char ch;
  while (std::cin >> ch) {
    if (isdigit(ch)) {
      n = n * 10 + ch - '0';
    }
  }
  if (ispalin(n)) {
    int ans = 0;
    while (n) ans += n % 10, n /= 10;
    std::cout << ans;
  } else {
    std::cout << n % 10;
  }
  return 0;
}