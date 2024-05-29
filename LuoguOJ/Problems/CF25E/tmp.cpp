#include <bits/stdc++.h>
using namespace std;

void solve() {
  string sk;
  getline(cin, sk);
  transform(sk.begin(), sk.end(), sk.begin(), ::tolower);
  vector<char> st;
  set<char> st1;
  map<char, char> mp1;
  map<char, char> mp2;
  int cnt = 0;
  for (int i = 0; i < sk.length(); i++) {
    if (sk[i] >= 'a' && sk[i] <= 'z' && st1.count(sk[i]) == 0) {
      st.push_back(sk[i]);
      st1.insert(sk[i]);
    }
  }

  for (auto u : st) {
    mp1[char('a' + cnt)] = u;
    mp2[u] = char('a' + cnt);
    cnt++;
  }
  int num = st.size();
  int j = 0;
  for (int i = num; i <= 25; i++) {
    for (; j < 26; j++) {
      if (st1.count(char('a' + j)))
        continue;
      else {
        mp1['a' + i] = char('a' + j);
        mp2['a' + j] = char('a' + i);
        st1.insert(char('a' + j));
        break;
      }
    }
  }
  string op;
  while (cin >> op) {
    if (op == "encryption") {
      string qq;
      while (qq == "")
        getline(cin, qq);
      for (int i = 0; i < qq.length(); i++) {
        if (mp1[qq[i]]) {
          cout << char(mp1[qq[i]] + 'A' - 'a');
        } else
          cout << qq[i];
      }
      cout << endl;
    } else if (op == "decryption") {
      string qq;
      while (qq == "")
        getline(cin, qq);
      transform(qq.begin(), qq.end(), qq.begin(), ::tolower);
      for (int i = 0; i < qq.length(); i++) {
        if (mp2[qq[i]]) {
          cout << char(mp2[qq[i]]);
        } else
          cout << qq[i];
      }
      cout << endl;
    } else if (op == "END") {
      cout << "Thanks for using goodbye!";
      break;
    }
  }
  return;
}

int main() {
  solve();
  return 0;
}