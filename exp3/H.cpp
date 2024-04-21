#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // freopen("H.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  queue<int> q;
  int in = 1;
  for (int i = 0; i < m; i++) {
    int op;
    cin >> op;
    if (op) q.push(q.front()), q.pop();
    else q.push(in++);
  }
  int len = q.size();
  for (int i = 0; i < len; i++) {
    if (i) cout << ' ';    
    cout << q.front(), q.pop();
  }
  return 0;
}