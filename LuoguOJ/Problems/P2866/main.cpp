// a看b等价于b看a

#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  long long N, ans = 0;
  cin >> N;
  stack<int> st;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    while (!st.empty() && st.top() <= a) st.pop();
    ans += st.size();
    st.push(a);
  }
  cout << ans;
  return 0;
}