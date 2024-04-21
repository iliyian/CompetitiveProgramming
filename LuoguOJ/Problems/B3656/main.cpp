// 链表是不连续内存的双端队列

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<list<int>> v;
  for (int i = 0; i < n; i++) {
    string op;
    int a, x;
    cin >> op >> a;
    if (v.size() < a) v.resize(a);
    auto &q = v[--a];
    if (op == "push_back") {
      cin >> x;
      q.push_back(x);
    }
    if (op == "push_front") {
      cin >> x;
      q.push_front(x);
    }
    if (op == "pop_back" && !q.empty()) {
      q.pop_back();
    }
    if (op == "pop_front" && !q.empty()) {
      q.pop_front();
    }
    if (op == "size") {
      cout << q.size() << '\n';
    } 
    if (op == "front" && !q.empty()) {
      cout << q.front() << '\n';
    }
    if (op == "back" && !q.empty()) {
      cout << q.back() << '\n';
    }
  }
  return 0;
}