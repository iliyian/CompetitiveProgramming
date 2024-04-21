#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string str;
  cin >> str;
  int l = str.find('1'), r = str.rfind('0');
  if (l == string::npos || r == string::npos) {
    cout << str;
    return 0;
  }
  reverse(str.begin() + l, str.begin() + r + 1);
  cout << str;
  return 0;
}