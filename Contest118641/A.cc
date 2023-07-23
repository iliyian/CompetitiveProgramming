#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];
    if (isdigit(ch)) a++;
    else if (isupper(ch)) c++;
    else if (islower(ch)) b++;
  }
  cout << a << ' ' << b << ' ' << c;
  return 0;
}