#include <bits/stdc++.h>
using namespace std;

int a[30000];

int gcd(int a, int b) {
  return b ? a : gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int g = a[0], l;
  for (int i = 1; i < n; i++) {
    g = gcd(g, a[i]);
  }
  cout << "g=" << g << endl;
}

int main() {
  int T;
  while (T--) solve();
  return 0;
}