#include <bits/stdc++.h>
using namespace std;

string add(string a, const string &b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < b.size(); i++) {
    a[i] += b[i];
  }
  for (int i = 1; i < a.size(); i++) {
    a[i] += a[i - 1] / 10;
    a[i - 1] %= 10;
  }
  while (!a.back()) a.pop_back();
  while (a.back() > 9) {
    a.push_back(a.back() / 10);
    a[a.size() - 2] %= 10;
  }
  return a;
}

int main() {
  int n;
  cin >> n;
  string prev, cur, temp; prev.push_back(1); cur.push_back(1);
  for (int i = 2; i <= n; i++) {
    temp = add(prev, cur);
    prev = cur; cur = temp;
  }
  for (int i = cur.size() - 1; i >= 0; i--) {
    cout << char(cur[i] + '0');
  }
  return 0;
}