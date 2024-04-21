#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int gans = 0, bans = 0;
  string girl("girl"), boy("boy");
  for (int i = 4; i >= 1; i--) {
    for (int j = 0; j < 4; j++) {
      int r = j + i;
      if (r > 4) continue;
      string target = girl.substr(j, i);
      // cout << "Target=" << target << endl;
      int pos = s.find(target);
      while (pos != string::npos) {
        gans++;
        for (int k = pos; k < pos + i; k++) s[k] ='.';
        // cout << "j=" << j << ",r=" << r << endl;
        pos = s.find(target);
      }
    }
  }
  for (int i = 3; i >= 1; i--) {
    for (int j = 0; j < 3; j++) {
      int r = j + i;
      if (r > 3) continue;
      string target = boy.substr(j, i);
      // cout << "Target=" << target << endl;
      int pos = s.find(target);
      while (pos != string::npos) {
        bans++;
        for (int k = pos; k < pos + i; k++) s[k] ='.';
        pos = s.find(target);
      }
      // cout << "s=" << s << endl;
    }
  }
  cout << bans << endl << gans;
  return 0;
}