#include <bits/stdc++.h>
using namespace std;

void solve() {
  stack<unsigned long long> s;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string op;
    cin >> op;
    if (op == "push") {
      unsigned long long x;
      cin >> x;
      s.push(x);
    } else if (op == "pop") {
      if (s.empty()) cout << "Empty\n";
      else s.pop();
    } else if (op == "query") {
      if (s.empty()) cout << "Anguei!\n";
      else cout << s.top() << '\n';
    } else if (op == "size") {
      cout << s.size() << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}