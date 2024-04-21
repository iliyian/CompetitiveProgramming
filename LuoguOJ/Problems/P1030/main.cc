#include <iostream>
#include <string>
using namespace std;

// Root is branch likewise.
void printTree(const string &a, const string &b) {
  // cout << "a=" << a << ",b=" << b << endl;
  if (a.empty()) return;
  if (a.size() == 1) {
    cout << a;
    return;
  }

  char root = b.back();
  cout << root;

  int n = a.find(root);
  string a1 = a.substr(0, n), a2 = a.substr(n+1, a.size()-n);
  int m = b.find_first_not_of(a1);
  string b1 = b.substr(0, m), b2 = b.substr(m, b.size()-1-m);


  printTree(a1, b1);
  printTree(a2, b2);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;

  printTree(a, b);
  return 0;
}