#include <iostream>
#include <string>
using namespace std;

int main() {
  string isbn;
  cin >> isbn;
  int len = isbn.size(), sum = 0, count = 1;
  for (int i = 0; i < len-2; i++) {
    char c = isbn[i];
    if (c != '-') {
      // cout << "sum=" << sum << endl;
      sum += (isbn[i] - '0') * count;
      count++;
    }
  }
  int mod = sum % 11;
  // cout << "mod=" << mod << endl;
  if (isbn.back() - '0' == mod) cout << "Right";
  else cout << isbn.substr(0, len-1) << (mod < 10 ? mod : 'X');
  return 0;
}