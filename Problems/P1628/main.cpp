#include <bits/stdc++.h>
using namespace std;

vector<string> S;
priority_queue<string, vector<string>, greater<string>> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    S.push_back(str);
  }
  string T;
  cin >> T;
  for (auto &s : S) {
    if (s.find(T, 0) == 0)
      q.push(s);
  }
  while (!q.empty()) {
    cout << q.top() << '\n'; q.pop();
  }
  return 0;
}