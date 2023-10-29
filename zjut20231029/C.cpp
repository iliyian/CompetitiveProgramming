#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  string str;
  cin >> str;
  if (str == "0" || str == "-0") {
    cout << 0;
    return 0;
  }
  if (str.back() == '0' || str.front() != '-') {
    str.pop_back();
    if (str.empty()) {
      cout << 0;
    } else cout << str;
    return 0;
  }
  str.pop_back();
  if (str.size() == 1) {
    cout << -1;
    return 0;
  }
  long long t = stoll(str);
  cout << t - 1;
  return 0;
}