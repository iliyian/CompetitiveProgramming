#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int n, q;
  cin >> n >> q;
  map<string, vector<string>> m;
  for (int i = 0; i < n; i++) {
    string str, key;
    cin >> str;
    for (int j = 0; j < str.size(); j++) {
      if (isupper(str[j]))
        key.push_back(str[j]);
    }
    m[key].push_back(str);
  }
  for (int i = 0; i < q; i++) {
    string str;
    cin >> str;
    auto &v = m[str];
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
      cout << v[i] << '\n';
  }
  return 0;
}