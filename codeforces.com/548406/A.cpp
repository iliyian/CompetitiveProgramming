#include <bits/stdc++.h>
using namespace std;

void solve() {
  char a, b, c;
  std::cin >> a >> b >> c;
  std::cout << a - '0' + c - '0' << '\n';
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}