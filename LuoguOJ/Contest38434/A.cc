#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a[0] == 'y' && b[0] == 'y' && c == "ding" && d == "zhen")
      cout << "Yes";
    else 
      cout << "No";
    cout << endl;
  }
  return 0;
}