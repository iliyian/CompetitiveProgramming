#include <bits/stdc++.h>
using namespace std;

int main() {
  int M, S, T, s1 = 0, s2 = 0;
  cin >> M >> S >> T;
  for (int i = 0; i < T; i++) {
    s1 += 17;
    if (M >= 10) {
      s2 += 60; M -= 10;
    } else M += 4;

    if (s2 > s1) s1 = s2;
    if (s1 > S) {
      cout << "Yes" << '\n' << i + 1;
      return 0;
    }
  }
  cout << "No" << '\n' << s1;
  return 0;
}