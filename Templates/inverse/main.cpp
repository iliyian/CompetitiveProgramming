#include <bits/stdc++.h>
using namespace std;

void exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}


int inv[3000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, p, x, y;
  cin >> n >> p;
  inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    cout << inv[i] << '\n';
  }
  return 0;
}