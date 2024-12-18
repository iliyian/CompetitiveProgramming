#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void rprint(string s) {
  if (s[0] == '0' && s.size() == 1) {
    cout << 0;
    return;
  }
  bool head = true;
  reverse(s.begin(), s.end());
  s.erase(0, s.find_first_not_of('0'));
  cout << s;
}

int main() {
  string s;
  cin >> s;
  if (s.find('.') != string::npos) {
    int pos = s.find('.');
    rprint(s.substr(0, pos));
    cout << '.';

    string r = s.substr(pos + 1, s.size() - pos - 1);
    if (r == to_string(0)) {
      cout << 0;
      return 0;
    }
    r.erase(0, r.find_first_not_of('0'));
    reverse(r.begin(), r.end());
    cout << r;
  } else if (s.find('/') != string::npos) {
    int pos = s.find('/');
    rprint(s.substr(0, pos));
    cout << '/';

    rprint(s.substr(pos + 1, s.size() - pos - 1));
  } else if (s.find('%') != string::npos) {
    rprint(s.substr(0, s.size()-1));
    cout << '%';
  } else {
    rprint(s);
  }
  return 0;
}