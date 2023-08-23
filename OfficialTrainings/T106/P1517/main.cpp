// 我确信这题在别的oj做过

#include <bits/stdc++.h>
using namespace std;

string operator * (const string &a, const string &b) {
  string c(a.size() + b.size() + 1, 0);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      c[i + j] += a[i] * b[j];
      if (c[i + j] >= 10) {
        c[i + j + 1] += c[i + j] / 10;
        c[i + j] %= 10;
      }
    }
  }
  while (!c.back() && c.size() >= 2) c.pop_back();
  while (c.back() >= 10) {
    c.push_back(c.back() / 10);
    c[c.size() - 2] %= 10;
  }
  return c;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  string s;
  int n;
  while (cin >> s >> n) {
    int len = 0, pos = s.find('.');
    if (pos != string::npos) {
      while (s.back() == '0') s.pop_back();
      len = n * (s.size() - 1 - pos);
      s.erase(pos, 1);
    }
    reverse(s.begin(), s.end());
    for (auto &c : s) c -= '0';
    
    string res(1, 1);
    while (n) {
      if (n & 1) res = res * s;
      s = s * s;
      n >>= 1;
    }
    
    reverse(res.begin(), res.end());
    if (len >= res.size()) {
      cout << ".";
      len -= res.size();
      for (int i = 0; i < len; i++) cout << 0;
      while (!res.back() && res.size() >= 2) res.pop_back();
      for (int i = 0; i < res.size(); i++) cout << char(res[i] + '0');
    } else {
      for (int i = 0; i < res.size(); i++) {
        cout << char(res[i] + '0');
        if (i == res.size() - 1 - len && len) cout << '.';
      }
    }
    cout << '\n';
  }
  return 0;
}