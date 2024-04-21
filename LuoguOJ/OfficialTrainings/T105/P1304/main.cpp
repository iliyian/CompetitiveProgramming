#include <iostream>
using namespace std;

bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

int main() {
  int n, a = 4;
  cin >> n;
  for (int i = 1; i <= (n - 2) / 2; i++) {
    for (int j = 2; j <= a / 2; j++) {
      if (isPrime(j) && isPrime(a - j)) {
        cout << a << "=" << j << "+" << a - j << endl;
        break;
      }
    }
    a += 2;
  }
  return 0;
}