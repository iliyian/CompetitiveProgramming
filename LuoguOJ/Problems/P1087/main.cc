#include <iostream>
#include <cmath>
#include <string>
using namespace std;

char checkType(const string &s) {
  bool has0 = false, has1 = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') has1 = true;
    if (s[i] == '0') has0 = true;
  }
  if (has0 && has1) return 'F';
  if (has1) return 'I';
  if (has0) return 'B';
  
  return 0;
}

void printTree(string s) {
  int len = s.size();
  if (len == 1) {
    cout << checkType(s);
    return;
  }

  printTree(s.substr(0, len/2));
  printTree(s.substr(len/2, len/2));
  cout << checkType(s); 
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("data.in", "r", stdin);

  int n;
  string S;
  cin >> n >> S;

  printTree(S);
  return 0;
}