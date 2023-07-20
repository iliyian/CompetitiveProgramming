#include <bits/stdc++.h>
using namespace std;

stack<int> sta;

int main() {
  char ch;
  int n = 0;
  while (ch = getchar(), ch != '@') {
    if (ch == '.') sta.push(n), n = 0;
    else if (isdigit(ch)) n = n * 10 + ch - '0';
    else {
      int b = sta.top(); sta.pop();
      int a = sta.top(); sta.pop();
      switch (ch) {
        case '+':
          sta.push(a + b);
        break;
        case '-':
          sta.push(a - b);
        break;
        case '*':
          sta.push(a * b);
        break;
        case '/':
          sta.push(a / b);
        break;
      }
    }
  }
  cout << sta.top();
  return 0;
}