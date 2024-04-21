#include <bits/stdc++.h>
using namespace std;

stack<int> sta;

int main() {
  int a, b, m = 10000;
  char ch;
  scanf("%d", &a);
  sta.push(a % m);
  while (scanf("%c%d", &ch, &b) == 2) {
    if (ch == '*') {
      a = sta.top(); sta.pop();
      sta.push(a % m * (b % 10000));
    } else {
      sta.push(b);
    }
  }
  int ans = 0;
  while (!sta.empty()) ans = (ans + sta.top()) % 10000, sta.pop();
  printf("%d", ans);
  return 0;
}