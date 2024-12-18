#include <bits/stdc++.h>
using namespace std;

struct Node {
  int i;
  Node *left, *right;
};

array<Node, 101> nodes;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    nodes[i] = Node{i};

  nodes[1].left = &nodes[n], nodes[1].right = &nodes[2];
  nodes[n].right = &nodes[1], nodes[n].left = &nodes[n-1];
  for (int i = 2; i <= n - 1; i++)
    nodes[i].left = &nodes[i-1], nodes[i].right = &nodes[i+1];

  Node *cur = &nodes[1];
  int cnt = 1;
  for (int i = 1; cnt <= n; i++) {
    if (i % m == 0) {
      cout << cur->i << " ";
      cur->left->right = cur->right, cur->right->left = cur->left;
      cnt++;
    }
    cur = cur->right;
  }
  return 0;
}