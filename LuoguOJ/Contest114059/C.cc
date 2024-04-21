#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
  char x, z;
  long long y, w;

  cin >> x >> y >> z >> w;

  if (x != z || !islower(x)) {
    cout << "Invalid" << endl << -1;
    return 0;
  }
  cout << "valid" << endl << abs(y - w) + 1;
  return 0;
}