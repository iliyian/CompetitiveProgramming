#include <bits/stdc++.h>
using namespace std;

unsigned long long pow2(int b) {
  if (b <= 0) return 1;
  return 1uLL << b;
}

int main() {
  int n;
  unsigned long long k;
  bool f = true;
  cin >> n >> k;
  while (n--) {
    unsigned long long p = pow2(n);
    if (k >= p) cout << (f ? 1 : 0), k -= p, f = false;
    else cout << (f ? 0 : 1), f = true;
  }
  return 0;
}