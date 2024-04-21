#include <bits/stdc++.h>
using namespace std;

long long solve(long long x, long long y) {
  if (y == 0) return 0;
  return solve(y, x % y) + 4 * y * (x / y);
}

int main() {
  long long x, y;
  cin >> x >> y;
  if (x < y) swap(x, y);
  cout << solve(x, y);
  return 0;
}