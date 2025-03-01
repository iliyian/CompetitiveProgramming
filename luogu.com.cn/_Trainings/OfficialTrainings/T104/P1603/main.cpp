#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

string simplenums[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
string complexnums[] = {"first", "second", "third"};

int getVal(string &s) {
  string *pos1 = find(simplenums, simplenums + 20, s);
  if (pos1 != simplenums + 20) {
    int n = pos1 - simplenums + 1;
    return (n * n) % 100;
  }
  string *pos2 = find(complexnums, complexnums + 3, s);
  if (pos2 != complexnums + 3) {
    int n = pos2 - simplenums + 1;
    return (n * n) % 100;
  }
  if (s == "a" || s == "another") return 1;
  if (s == "both") return 4;
  return -1;
}

int main() {
  string s;
  string ss[6]; 
  for (int i = 0; i < 6; i++) {
    cin >> s;
    int v = getVal(s);
    // cout << "v=" << v << endl;
    if (v >= 0) {
      ss[i] = to_string(v);
      if (ss[i].size() == 1) ss[i] = '0' + ss[i];
    }
  }
  sort(ss, ss + 6);
  bool head = true;
  stringstream sss;
  for (int i = 0; i < 6; i++) {
    // if (head && ss[i][0] == '0') cout << ss[i][1];
    // else cout << ss[i];

    // if (!ss[i].empty()) {
    //   head = false;
    // }
    // cout << "i=" << i << ",ss=" << ss[i] << endl;
    sss << ss[i];
  }
  string ans = string(sss.str());
  if (ans.size() == 0) {
    cout << 0;
    return 0;
  }
  int pos = ans.find_first_not_of('0');
  ans = ans.substr(pos, ans.size() - pos);
  cout << ans;
  // if (head) cout << 0;
  return 0;
}