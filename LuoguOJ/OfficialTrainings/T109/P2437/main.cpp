#include <bits/stdc++.h>
using namespace std;

string add(string a, const string &b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < b.size(); i++) {
    a[i] += b[i];
    if (a[i] > 9 && i < b.size() - 1) { // 否则导致size不更新
      a[i + 1] += a[i] / 10;
      a[i] %= 10;
    }
  }
  while (a.back() > 9) {
    a.push_back(a.back() / 10);
    a[a.size() - 2] %= 10;
  }
  return a;
}

int main() {
  int m, n;
  cin >> m >> n;
  int t = n - m;
  string prev, cur; prev.push_back(1); cur.push_back(1);
  for (int i = 1; i < t; i++) {
    string t = add(prev, cur);
    prev = cur; cur = t;
  }
  for (int i = cur.size() - 1; i >= 0; i--)
    cout << char(cur[i] + '0');
  return 0;
}