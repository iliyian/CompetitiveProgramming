// 第一道回头看，修好的题目

#include <bits/stdc++.h>
using namespace std;

string ans, temp;

string mul(string &a, const string &b) {
  int alen = min(500, int(a.size())), blen = min(500, int(b.size()));
  string c; c.resize(alen + blen, 0);
  for (int i = 0; i < alen; i++) {
    if (i >= a.size()) break;
    for (int j = 0; j < blen; j++) {
      if (j >= b.size()) break;
      c[i + j] += a[i] * b[j];
      if (c[i + j] >= 10) {
        c[i + j + 1] += c[i + j] / 10;
        c[i + j] %= 10;
      }
    }
  }
  while (c.size() > 500) c.pop_back();
  while (!c.back() && c.size() >= 2) c.pop_back(); 
  return c;
}

int main() {
  int P;
  cin >> P;
  int t = P;
  ans.push_back(1);

  string b; b.push_back(2);

  while (P) {
    if (P & 1) ans = mul(ans, b);
    b = mul(b, b);
    P >>= 1;
  }

  int i = 0; ans[0]--;
  while (ans[i] < 0) {
    ans[i] += 10;
    ans[i + 1]--;
    i++;
  }

  cout << int(t * log10(2) + 1) << '\n';

  for (int i = 499; i >= 0; i--) {
    if (i >= ans.size()) cout << 0;
    else cout << char(ans[i] + '0');
    
    if (i % 50 == 0) cout << '\n';
  }
  return 0;
}