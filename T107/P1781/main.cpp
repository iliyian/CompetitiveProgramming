// string竟然也tmd能比大小

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, mi = -1;
  string mn;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string a;
    cin >> a;

    if (a.size() > mn.size() || (a.size() == mn.size() && a > mn)) {
      mn = a, mi = i;
    }
  }
  cout << mi << '\n' << mn;
  return 0;
}