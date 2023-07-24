#include <bits/stdc++.h>
using namespace std;

long long bordersum(int n) {
  long long sum = 0;
  for (int i = 1; i <= n; i++) sum += i;
  return sum;
}

long long squarecount(int n, int m, int len) {
  return (n - len + 1) * (m - len + 1);
}

int main() {
  int n, m;
  cin >> n >> m;
  long long bn = bordersum(n), bm = bordersum(m);
  long long squaresum = 0;
  for (int i = 1; i <= min(n, m); i++) squaresum += squarecount(n, m, i);
  cout << squaresum << " " << (bn * bm - squaresum);
  return 0;
}