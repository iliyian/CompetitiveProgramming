#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    string str;
    cin >> str;
    int pos;
    cin >> pos;
    --pos;

    string st;
    int curlen = str.size();
    str.push_back(0);

    for (int i = 0; i < str.size(); i++) {
      while (pos >= curlen && !st.empty() && st.back() > str[i]) {
        pos -= curlen;
        curlen--;
        st.pop_back();
      }
      st.push_back(str[i]);
    }

    cout << st[pos];
  }
  return 0;
}