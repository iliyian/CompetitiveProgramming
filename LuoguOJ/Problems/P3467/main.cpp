#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  stack<int> st;
  int ans = n;
  for (int i = 0; i < n; i++) {
    int w, h;
    cin >> w >> h;
    while (!st.empty() && st.top() >= h) {
      ans -= st.top() == h;
      st.pop();
    }
    st.push(h);
  }
  cout << ans;
  return 0;
}