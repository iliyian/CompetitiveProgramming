#include <bits/stdc++.h>
using namespace std;

int lch[30], rch[30];

void print(char root) {
  if (root == '*') return;
  cout << root;
  print(lch[root]);
  print(rch[root]);
}

int main() {
  int n;
  char root;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char a, b, c;
    cin >> a >> b >> c;
    lch[a] = b, rch[a] = c;
    if (!i) root = a;
  }
  print(root);
  return 0;
}