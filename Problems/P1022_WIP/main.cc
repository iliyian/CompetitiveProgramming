#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;

  int digit = 0, cfact = 0, ufact = 0, sig = 1;
  if (str[0] == '-') sig = -1;
  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];
    if (isdigit(ch)) {
      digit *= 10;
      digit += (ch - '0') * sig;
    } else if (ch == '-') {
      sig = -1;
    } else if (ch == '+')
  }

  return 0;
}