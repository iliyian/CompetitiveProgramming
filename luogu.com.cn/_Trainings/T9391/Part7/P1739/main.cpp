// 这题审题错了，只有小括号，反正AC，算了

#include <bits/stdc++.h>
using namespace std;

stack<int> sta;
map<char, char> m;

int main() {
  char ch;
  m.insert(make_pair(')', '('));
  m.insert(make_pair(']', '['));
  m.insert(make_pair('}', '{'));
  while (ch = getchar(), ch != '@') {
    if (m[ch]) {
      if (sta.empty() || sta.top() != m[ch]) {
        cout << "NO"; return 0;
      }
      sta.pop();
    } else if (ch == '(' || ch == '[' || ch == '{')
      sta.push(ch);
  }
  cout << (sta.empty() ? "YES" : "NO");
  return 0;
}