#include <bits/stdc++.h>
#define int long long

int n, r;

void write(int x) {
  if (!x) return;
  write(x / r);
  int rest = x % r;
  if (rest <= 9) {
    std::cout << rest;
  } else {
    std::cout << char('A' + rest - 10);
  }
}

signed main() {
  std::cin >> n >> r;
  write(n);
  
  return 0;
}