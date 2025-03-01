#include <bits/stdc++.h>
using namespace std;

bitset<8> bits;
vector<bool> v;

void print(int cnt, int clr) {
  bitset<8> bits(cnt);
  bits[7] = clr;
  cout << bits.to_ullong() << ' ';
}

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n / 8; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < 8; j++)
      v.push_back(x >> (7 - j) & 1);
  }
  bool prev = v.front(), clr = v.front();
  int cnt = 1;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] == prev) cnt++;
    else {
      print(cnt, clr);
      clr = v[i];
      prev = clr;
      cnt = 1;
    }
  }
  print(cnt, clr);
  return 0;
}