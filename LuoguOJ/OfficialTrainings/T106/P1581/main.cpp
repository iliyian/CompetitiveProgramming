// 题目坑人，谁说只有万位，明明有十万位

#include <bits/stdc++.h>
using namespace std;

string str;
int d[] = {2, 3, 5, 7, 11, 13};

void change(int l, int r, vector<int> &v) {
  int pos = str.rfind(',', r), pre = r;
  while (pos < r && pos >= l) {
    v.push_back(stoi(str.substr(pos + 1, pre - pos - 1)));
    pre = pos;
    pos = str.rfind(',', pos - 1);
  }
  v.push_back(stoi(str.substr(l, pre - l)));
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> str;
  int split = str.find('+');
  vector<int> a, b;
  change(0, split, a);
  change(split + 1, str.size(), b);
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < b.size(); i++)
    a[i] += b[i];
  for (int i = 0; i < a.size() - 1; i++)
    if (a[i] >= d[i]) {
      a[i + 1] += a[i] / d[i];
      a[i] %= d[i];
    }
  while (a.back() >= d[a.size() - 1]) {
    a.push_back(a.back() / d[a.size() - 1]);
    a[a.size() - 2] %= d[a.size() - 2];
  }
  for (int i = a.size() - 1; i >= 0; i--) {
    cout << a[i];
    if (i) cout << ',';
  }
  return 0;
}