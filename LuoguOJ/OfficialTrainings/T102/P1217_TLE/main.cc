#include <bits/stdc++.h>
using namespace std;


// todo
int genPalin(int n) {
  int m = n, t = n, len = 0;
  while (n) len++, n /= 10;
  for (int i = 0; i < len; i++) {
    m = m * 10 + t % 10;
    t /= 10;
  }
  return m;
}

bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= b; i++) {
    int n = genPalin(i);
    if (n < a) continue;
    if (n > b) break;
    if (isPrime(n)) cout << n << '\n';
  }
  return 0;
}