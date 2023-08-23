#include <bits/stdc++.h>
using namespace std;

string& check(string &a) {
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] >= 10) {
      a[i + 1] += a[i] / 10;
      a[i] %= 10;
    }
  }
  while (a.back() >= 10) {
    a.push_back(a.back() / 10);
    a[a.size() - 2] %= 10;
  }
  return a;
}

string solve(int n) {
  if (n == 1) {
    string temp; temp.push_back(1);
    return temp;
  }
  string temp = solve(n - 1);
  for (int i = 0; i < temp.size(); i++) temp[i] *= 2;
  check(temp);
  temp[0] += 1;
  return check(temp);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  string ans = solve(n);
  for (int i = 0; i < ans.size(); i++)
    ans[i] *= 2;
  for (int i = check(ans).size() - 1; i >= 0; i--)
    cout << char(ans[i] + '0');
  return 0;
}