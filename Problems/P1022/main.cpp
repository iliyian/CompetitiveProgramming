// 模块化模型化思维方式

#include <bits/stdc++.h>
using namespace std;

int param = 0, constant = 0;

void parse(string str, int pos) {
  if (str[0] != '-') str = '+' + str;
  for (int i = 0; i < str.size(); i++) {
    if (isalpha(str[i]) && !isdigit(str[i - 1]))
      str.insert(i, "1");
  }

  int ops[100], cnt = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '+' || str[i] == '-') {
      ops[cnt++] = i;
    }
  }

  ops[cnt++] = str.size();
  for (int i = 0; i < cnt-1; i++) {
    bool f = false;
    int l = ops[i] + 1, r = ops[i + 1], n = 0;
    if (isalpha(str[r-1])) r--, f = true;
    for (int j = l; j < r; j++) {
      n = n * 10 + str[j] - '0';
    }
    int sig = 1;
    if (str[ops[i]] == '-') sig = -1;
    if (f) param += n * sig * pos;
    else constant += n * sig * pos;
  }

}

int main() {
  freopen("data.in", "r", stdin);
  string str;
  cin >> str;
  int split = str.find('=');
  char al;
  for (int i = 0; i < str.size(); i++) if (isalpha(str[i])) {al = str[i]; break;}
  
  parse(str.substr(0, split), 1);
  parse(str.substr(split + 1, str.size() - split - 1), -1);

  double res = double(-constant) / param;
  if (!res) res = 0;
  cout << al << '=' << fixed << setprecision(3) << res;
  return 0;
}