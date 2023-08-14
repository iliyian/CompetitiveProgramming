#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int sum = a + b + c + d + e;
  if (sum < 100) {
    cout << "Gray";
  } else if (sum < 120) {
    cout << "Blue";
  } else if (sum < 170) {
    cout << "Green";
  } else if (sum < 230) {
    cout << "Orange";
  } else {
    cout << "Red";
  }
  return 0;
}