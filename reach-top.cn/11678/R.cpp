#include <bits/stdc++.h>
#define int long long

int sum(int x) {
  int n = 0;
  while (x) n += x % 10, x /= 10;
  return n;
}

signed main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string n;
    std::cin >> n;
    int s = 0;
    for (int i = n.size() - 1; i >= 0; i--) {
      if ((n.size() - 1 - i) % 2 == 0) {
        int t = (n[i] - '0') * 7;
        while (t > 9) t = sum(t);
        n[i] = t + '0';
      }
      s += n[i] - '0';
    }
    std::cout << (s % 8 == 0 ? "T" : "F") << '\n';
  }
  
  return 0;
}