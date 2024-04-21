// 二分以递增以伪装priority_queue

#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  int n, a;
  cin >> n;
  cin >> a;
  v.push_back(a);
  for (int i = 0; i < (n - 1) / 2; i++) {
    cout << v[v.size() / 2] << endl;
    int b, c;
    cin >> b >> c;
    v.insert(lower_bound(v.begin(), v.end(), b), b);
    v.insert(lower_bound(v.begin(), v.end(), c), c);
  }
  cout << v[v.size() / 2] << endl;
  return 0;
}