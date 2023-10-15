#include <bits/stdc++.h>
using namespace std;

int f[1002][1002];

int main() {
  string str, rstr;
  cin >> str;
  str = '#' + str + '#';
  for (auto it = str.rbegin(); it != str.rend(); it++)
    rstr.push_back(*it);
  memset(f, 0, sizeof(f));
  for (int i = 1; i < str.size() - 1; i++) {
    for (int j = 1; j < rstr.size() - 1; j++) {
      f[i][j] = str[i] == rstr[j] ? f[i - 1][j - 1] + 1 : max(f[i][j - 1], f[i - 1][j]);
    }
  }
  cout << str.size() - 2 - f[str.size() - 2][str.size() - 2];
  return 0;
}