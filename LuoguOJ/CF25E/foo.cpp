#include <bits/stdc++.h>
#include <cctype>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string key;

  while (getline(cin, key)) {

  vector<int> vis(26);
  vector<char> v, rev(26);
  for (char ch : key) {
    if (isalpha(ch) && !vis[tolower(ch) - 'a']) {
      vis[tolower(ch) - 'a'] = true;
      v.push_back(tolower(ch));
    }
  }
  for (int i = 0; i < 26; i++) {
    if (!vis[i]) {
      v.push_back(char(i + 'a'));
    }
  }
  for (int i = 0; i < v.size(); i++) {
    rev[v[i] - 'a'] = 'a' + i;
  }
  string op;
  while (cin >> op) {
    if (op == "decryption") {
      string str;
      while (str == "") getline(cin, str);
      for (char ch : str) {
        if (isupper(ch)) {
          cout << rev[ch - 'A'];
        } else {
          cout << ch;
        }
      }
    } else if (op == "encryption") {
      string str;
      while (str == "") getline(cin, str);
      for (char ch : str) {
        if (islower(ch)) {
          cout << char(toupper(v[ch - 'a']));
        } else {
          cout << ch;
        }
      }
    } else {
      cout << "Thanks for using goodbye!";
      break;
    }
    cout << '\n';
  }}

  return 0;
}