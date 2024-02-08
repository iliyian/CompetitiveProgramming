#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  if (k % 2 == 0) {
    sort(str.begin(), str.end());
    cout << str << '\n';
    return;
  }
  string odd, even;
  for (int i = 0; i < str.size(); i++) {
    if ((i + 1) % 2 == 0) {
      even.push_back(str[i]);
    } else {
      odd.push_back(str[i]);
    }
  }
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());
  int oi = 0, ei = 0;
  for (int i = 0; i < str.size(); i++) {
    if ((i + 1) % 2 == 0) {
      cout << even[oi++];
    } else {
      cout << odd[ei++];
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}