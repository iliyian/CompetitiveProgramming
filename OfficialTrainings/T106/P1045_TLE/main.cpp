#include <bits/stdc++.h>
using namespace std;

string ans, temp;

string mul(string &a, const string &b) {
  string c; c.resize(a.size() + b.size() + 1, 0);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      c[i + j] += a[i] * b[j];

      c[i + j + 1] += c[i + j] / 10;
      c[i + j] %= 10;
    }
  }
  while (!c.back()) c.pop_back();
  return c;
}

int main() {
  int P;
  cin >> P;
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

  cout << ans.size() << '\n';

  for (int i = 499; i >= 0; i--) {
    cout << (i >= ans.size() ? '0' : char(ans[i] + '0'));

    if (!(i % 50)) cout << '\n';
  }
  return 0;
}