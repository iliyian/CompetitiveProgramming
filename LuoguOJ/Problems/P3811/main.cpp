#include <bits/stdc++.h>
using namespace std;

int inv[3000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, p;
  cin >> n >> p;
  inv[1] = 1;
  cout << 1 << '\n';
  for (int i = 2; i <= n; i++) {
    inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    cout << inv[i] << '\n';
  }
  return 0;
}