#include <bits/stdc++.h>
using namespace std;

bitset<8> bits;

int main() {
  int n;
  while (cin >> n) {
    bits = n;
    int prev = bits[7], clr = bits[7], cnt = 0;
    for (int i = 6; i >= 0; i--) {
      if (bits[i] == prev) cnt++;
      else {
        bitset<8> ans(cnt); ans[7] = clr;
        cout << ans.to_ullong();
        clr = bits[i];
        cnt = 0;
        cout << ' ';
      }
      prev = bits[i];
    }
  }
  return 0;
}