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
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      std::cout << i << ' ';
      if (i * i != n) {
        std::cout << n / i << ' ';
      }
    }
  }
  return 0;
}