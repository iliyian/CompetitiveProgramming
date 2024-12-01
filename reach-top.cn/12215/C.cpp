#include <bits/stdc++.h>

bool isprime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 2; i <= n; i++) {
    std::string t = std::to_string(i);
    if (std::count(t.begin(), t.end(), '5') && isprime(i)) {
      std::cout << i << '\n';
    }
  }
  return 0;
}