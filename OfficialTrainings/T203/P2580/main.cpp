#include <bits/stdc++.h>
using namespace std;

int nxt[500001][26], cnt = 0;
bitset<500001> exist, called;

void insert(const string &str) {
  int p = 0;
  for (int i = 0; i < str.size(); i++) {
    int ch = str[i] - 'a';
    if (!nxt[p][ch]) nxt[p][ch] = ++cnt;
    p = nxt[p][ch];
  }
  exist[p] = true;
}

bool find(const string &str, int &p) {
  p = 0;
  for (int i = 0; i < str.size(); i++) {
    int ch = str[i] - 'a';
    if (!nxt[p][ch]) return false;
    p = nxt[p][ch];
  }
  if (!exist[p] || called[p]) return false;
  called[p] = true;
  return true;
}

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    insert(str);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string str;
    cin >> str;
    int p;
    if (!find(str, p)) {
      if (called[p]) cout << "REPEAT\n";
      else cout << "WRONG\n";
    } else {
      cout << "OK\n";
    }
  }
  return 0;
}