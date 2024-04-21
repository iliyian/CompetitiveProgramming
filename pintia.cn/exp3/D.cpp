#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  int N;
  cin >> N;
  stack<int> st, ops;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    st.push(x);
  }
  for (int i = 0; i < N - 1; i++) {
    char op;
    cin >> op;
    ops.push(op);
  }
  for (int i = 0; i < N - 1; i++) {
    char op = ops.top(); ops.pop();
    int y = st.top(); st.pop();
    int x = st.top(); st.pop();
    if (op == '/') {
      if (y == 0) {
        cout << "ERROR: " << x << "/0";
        return 0;
      }
      st.push(x / y);
    }
    else if (op == '+') st.push(x + y);
    else if (op == '-') st.push(x - y);
    else st.push(x * y);
  }
  cout << st.top();
  return 0;
}