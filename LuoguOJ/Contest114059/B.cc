#include <iostream>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> head;
  while (n--) {
    int a;
    cin >> a;
    head.insert(a);
  }
  cout << head.size();
  return 0;
}