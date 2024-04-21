#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  long long b, n = 0;
  bool f = false;
  cin >> str >> b;
  if (str == "0") {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < str.size(); i++) {
    int a = str[i] - '0';
    n = n * 10 + a;
    int up = n / b;
    n %= b;
    if (up || f) f = true;
    if (f) cout << up;
  }
}