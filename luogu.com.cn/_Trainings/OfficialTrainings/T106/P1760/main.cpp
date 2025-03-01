// vector better for complex struct in performance
// string for small digits only, cuz char can only be up to 255, if to many multiplies with individual check() function
// it will be overflow when HP * HP

#include <bits/stdc++.h>
using namespace std;

void check(string &s) {
  for (int i = 0; i < s.size() - 1; i++)
    if (s[i] >= 10) {
      s[i + 1] += s[i] / 10;
      s[i] %= 10;
    }
  while (s.back() >= 10) {
    s.push_back(s.back() / 10);
    s[s.size() - 2] %= 10;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  string s;
  s.push_back(1);
  while (n--) {
    for (int i = 0; i < s.size(); i++)
      s[i] *= 2;
    check(s);
  }
  s[0]--; // impossible for ending 0;
  for (int i = s.size() - 1; i >= 0; i--)
    cout << char(s[i] + '0');
  return 0;
}