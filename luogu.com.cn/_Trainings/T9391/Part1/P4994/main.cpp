#include <bits/stdc++.h>
using namespace std;

int main() {
  int M;
  cin >> M;
  int prev = 1;
  int cur = 1, n = 1;
  for (;;) {
    if (prev % M == 0 && cur % M == 1) break;

    int t = prev;
    prev = cur;
    cur = (t + prev) % M;
    n++;
  }
  cout << n;
  return 0;
}