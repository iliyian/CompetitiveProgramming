#include <iostream>
#include <string>
using namespace std;

int main() {
  // freopen("data.out", "w", stdout);

  int q;
  string str;
  cin >> q >> str;
  while (q--) {
    int a, p1, p2;
    string s1, s2;
    cin >> a;
    switch (a) {
      case 1:
        cin >> s1;
        str += s1;
        cout << str;
        break;
      case 2:
        cin >> p1 >> p2;
        str = str.substr(p1, p2);
        cout << str;
        break;
      case 3:
        cin >> p1 >> s1;
        str = str.insert(p1, s1);
        cout << str;
        break;
      case 4:
        cin >> s1;
        int p = str.find(s1);
        cout << (p == string::npos ? -1 : p); 
      break;
    }
    cout << endl;
  }
  return 0;
}