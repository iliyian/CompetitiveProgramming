#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int N;
  cin >> N;
  queue<int> q;
  for (int i = 0; i < N; i++) {
    int op, x;
    cin >> op;
    switch (op) {
      case 1:
        cin >> x, q.push(x);
      break;
      case 2:
        if (q.empty()) cout << "ERR_CANNOT_POP\n";
        else q.pop();
      break;
      case 3:
        if (q.empty()) cout << "ERR_CANNOT_QUERY\n";
        else cout << q.front() << '\n';
      break;
      case 4:
        cout << q.size() << '\n';
      break;
    }
  }
  return 0;
}