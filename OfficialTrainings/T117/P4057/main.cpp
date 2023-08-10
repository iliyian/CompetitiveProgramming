#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long ab = a * b / gcd(a, b);
  long long abc = ab * c / gcd(ab, c);
  cout << abc;
  return 0;
}