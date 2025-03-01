#include <iostream>
using namespace std;

int main() {
  long long a1, a2, n;
  cin >> a1 >> a2 >> n;
  cout << n * a1 + (n - 1) * n * (a2 - a1) / 2;

  return 0;
}