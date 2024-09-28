#include <bits/stdc++.h>

bool check(int a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    ans += check(i);
  }
  std::cout << ans << '\n';
  return 0;
 }