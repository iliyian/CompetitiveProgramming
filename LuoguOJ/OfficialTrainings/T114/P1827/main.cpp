// pre, in, post，学会新单词，顺便给结构体二叉树遍历我还没练过
// 一直都是字符串
// 甚至可以inl, inr, prel, prer节省时空，但是AC了，而且我懒，2023/7/27 23:59

#include <bits/stdc++.h>
using namespace std;

void read(string in, string pre) {
  if (in.empty() || pre.empty()) return;
  char root = pre.front();
  int pos = in.find(root);
  read(in.substr(0, pos), pre.substr(1, pos));
  read(in.substr(pos + 1, in.size() - pos - 1), pre.substr(pos + 1, pre.size() - 1 - pos));
  cout << root;
}

int main() {
  string in, pre;
  cin >> in >> pre;
  read(in, pre);
  return 0;
}