#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("B.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  string str;
  getline(cin, str);
  for (auto &ch : str) {
    if (isalpha(ch)) {
      if (isupper(ch)) cout << char(tolower(ch));
      else cout << char(toupper(ch));
    } else cout << ch;
  }
  return 0;
}