// 可以 cin >> ch，妙

#include <bits/stdc++.h>
using namespace std;

map<string, string> pa;

string& find(string &x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  freopen("data.in", "r", stdin);
  string str, pre;
  while (cin >> str) {
    if (str == "$") break;
    char op = str[0];
    str = str.substr(1, str.size() - 1);
    switch(op) {
      case '#':
        if (!pa.count(str)) pa[str] = str;
        pre = str;
      break;
      case '+':
        pa[str] = pre;
      break;
      case '?':
        cout << str << ' ' << find(str) << '\n';
      break;
    }
  }
  return 0;
}