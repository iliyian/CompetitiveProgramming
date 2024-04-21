#include <bits/stdc++.h>
using namespace std;

set<string> s;

int main() {
  int n;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    s.insert(str);
  }
  cout << s.size();
  return 0;
}