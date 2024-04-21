#include <bits/stdc++.h>
using namespace std;

inline void change(char &ch) {
  ch = ch >= 10 ? ch - 10 + 'A' : ch + '0';
}
inline void rchange(char &ch) {
  ch = isdigit(ch) ? ch - '0' : ch - 'A' + 10;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int B;
  cin >> B;
  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < a.size(); i++) rchange(a[i]);
  for (int i = 0; i < b.size(); i++) rchange(b[i]);
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < b.size(); i++) {
    a[i] += b[i];
  }
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] >= B) {
      a[i + 1] += a[i] / B;
      a[i] %= B;
    }
    change(a[i]);
  }
  while (a.back() >= B) {
    a.push_back(a.back() / B);
    char &prev = a[a.size() - 2];
    prev %= B;
    change(prev);
  }
  change(a.back());
  reverse(a.begin(), a.end());
  cout << a;
  return 0;
}