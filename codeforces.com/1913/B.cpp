#include <bits/stdc++.h>
#define N 200005
using namespace std;

int s1[N], s0[N];

void solve() {
  string str;
  cin >> str;
  int cnt1 = 0, cnt0 = 0;
  str = '#' + str;
  int len = str.size();
  for (int i = 1; i <= len; i++)
    s1[i] = s1[i - 1] + (str[i] == '1'), cnt1 += str[i] == '1',
      s0[i] = s0[i - 1] + (str[i] == '0'), cnt0 += str[i] == '0'; 
  if (cnt1 == cnt0) {
    cout << 0 << '\n';
    return;
  }
  for (int i = 1; i <= len; i++) {
    if (!cnt1 && str[i] == '0' || !cnt0 && str[i] == '1') {
      cout << len - i << '\n';
      return;
    }
    cnt1 -= str[i] == '0';
    cnt0 -= str[i] == '1';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}