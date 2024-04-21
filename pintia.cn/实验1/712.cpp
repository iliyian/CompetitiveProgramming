#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  getline(cin, str);
  for (int i = 0; i < str.size(); i++) {
    char c = str[i];
    if (isalpha(c)) {
      if (c == 'z') c = 'a' - 1;
      if (c == 'Z') c = 'A' - 1;
      c++;
      if (isupper(c)) cout << char(tolower(c));
      else cout << char(toupper(c));
    } else cout << c;
  }
  return 0;
}