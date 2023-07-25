#include <bits/stdc++.h>
using namespace std;

bool check(const string &a, const string &b) {
  if (a.size() != b.size()) return false;
  for (int i = 0; i < a.size(); i++)
    if (tolower(a[i]) != tolower(b[i]))
      return false;
  return true;
}

bool read(string &s, int &space) {
  char ch = cin.get();
  bool f = false;
  int spacecount = 0;
  s.clear();
  while (f || isalpha(ch)) {
    if (isalpha(ch)) {
      s += ch;
    }
    if (isspace(ch)) spacecount++;
    ch = cin.get();
  }
  if (isspace(ch)) spacecount++;
  space = spacecount;
  if (ch == EOF) return false;
  return true;
}

int main() {
  string s, word;
  cin >> word;
  int count = 0, pos = 0;
  bool f = false;
  int space;
  while (read(s, space)) {
    if (check(word, s)) {
      if (!f) {
        f = true;
      }
      count++;
    }
    if (!f) pos += s.size() + space;
  }
  if (f)
    cout << count << " " << pos-1;
  else
    cout << -1;
  return 0;
}