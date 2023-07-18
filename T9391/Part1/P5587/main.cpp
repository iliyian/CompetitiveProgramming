// 大约做了两个小时了
// 2023/7/17 14:25
// 中午原味鸡蛮好吃

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string fixStr(const string &src) {
  string trg;
  for (int i = 0; i < src.size(); i++) {
    if (src[i] == '<' && !trg.empty()) trg.pop_back();
    if (src[i] != '<') trg.push_back(src[i]);
  }
  return trg;
}

int main() {
  freopen("data.in", "r", stdin);
  string str;
  vector<string> v;
  while (getline(cin, str), str != "EOF") {
    v.push_back(fixStr(str));
  }
  int sum = 0, idx = 0;
  while (getline(cin, str), str != "EOF") {
    string src = fixStr(str), trg = v[idx++];
    for (int i = 0; i < min(src.size(), trg.size()); i++)
      sum += src[i] == trg[i];
  }
  int T;
  cin >> T;
  cout << round(sum / (T / 60.0));
  return 0;
}