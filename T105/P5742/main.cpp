#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  int a, b;
  while (n--) {
    cin >> s >> a >> b;
    if (a + b > 140 && a * 7 + b * 3 >= 800)
      cout << "Excellent";
    else cout << "Not excellent";
    cout << endl;
  }
  return 0;
}