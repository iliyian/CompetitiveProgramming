#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, prev = 1, cur = 1;
  cin >> n;
  if (n == 1) {
    cout << "[1]";
  } else if (n == 2) {
    cout << "[1, 1]";
  } else {
    cout << "[1, 1, ";
    for (int i = 3; i <= n; i++) {
      int t = prev + cur;
      prev = cur;
      cur = t;
      cout << t << (i == n ? "]" : ", ");
    }
  }
  return 0;
}