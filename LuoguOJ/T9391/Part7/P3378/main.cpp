#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int op;
    cin >> op;
    switch (op) {
      case 1:
        int a; cin >> a;
        pq.push(a);
      break;
      case 2:
        cout << pq.top() << endl;
      break;
      case 3:
        pq.pop();
      break;
    }
  }
  return 0;
}