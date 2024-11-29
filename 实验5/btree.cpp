#include "btree.h"
#include <bits/stdc++.h>

BTree::BTree() : myRoot(0) {}

BTree::BTree(const std::vector<DataType> &init) { myRoot = build(init, 1); }

void BTree::copy(BinNode *root, BinNode *&rt) {
  if (!root)
    return;
  rt = new BinNode(root->data);
  copy(root->lchild, rt->lchild);
  copy(root->rchild, rt->rchild);
}

BTree::BTree(const BTree &other) { copy(other.myRoot, myRoot); }
BTree &BTree::operator=(const BTree &other) {copy(other.myRoot, myRoot); return *this;}

BinNode *BTree::build(const std::vector<DataType> &init, int pos) {
  if (pos - 1 >= init.size() || !init[pos - 1])
    return 0;
  BinNode *rt = new BinNode(init[pos - 1]);
  rt->lchild = build(init, pos * 2);
  rt->rchild = build(init, pos * 2 + 1);
  return rt;
}

bool BTree::empty() { return !myRoot; }

void BTree::DisplayBTree() {
  std::cout << "PreOrder Traversal: \n";
  preorder(myRoot);
  std::cout << '\n';
  preorder_stack(myRoot);
  std::cout << '\n';

  std::cout << "InOrder Traversal: \n";
  inorder(myRoot);
  std::cout << '\n';
  inorder_stack(myRoot);
  std::cout << '\n';

  std::cout << "PreOrder Traversal: \n";
  postorder(myRoot);
  std::cout << '\n';
  postorder_stack(myRoot);
  std::cout << '\n';

  std::cout << "LevelOrder Traversal: \n";
  levelorder(myRoot);
  std::cout << '\n';
}

BinNode *BTree::FindNode(BinNode *root, const DataType &x) const {
  if (!root)
    return 0;
  BinNode *ans = FindNode(root->lchild, x);
  if (ans)
    return ans;
  return FindNode(root->rchild, x);
}

int BTree::Nodes(BinNode *root) {
  if (!root)
    return 0;
  return Nodes(root->lchild) + Nodes(root->rchild) + 1;
}

int BTree::Height(BinNode *root) {
  if (!root)
    return 0;
  return std::max(Height(root->lchild), Height(root->rchild)) + 1;
}

int BTree::Leaves(BinNode *root) {
  if (!root)
    return 0;
  if (!root->lchild && !root->rchild)
    return 1;
  return Leaves(root->lchild) + Leaves(root->rchild);
}

void BTree::displayLeaves(BinNode *root) {
  if (!root)
    return;
  if (!root->lchild && !root->rchild) {
    std::cout << root->data;
    return;
  }
  displayLeaves(root->lchild);
  displayLeaves(root->rchild);
}

int BTree::levelX(BinNode *root, DataType x) {
  if (!root)
    return 0;
  if (root->data == x)
    return 1;
  int ans = levelX(root->lchild, x);
  if (ans)
    return ans + 1;
  ans = levelX(root->rchild, x);
  if (ans)
    return ans + 1;
  return 0;
}

int BTree::KCount(BinNode *root, int k) {
  if (!root || !k)
    return 0;
  if (k == 1)
    return 1;
  return KCount(root->lchild, k - 1) + KCount(root->rchild, k - 1);
}

void del(BinNode *root) {
  if (!root)
    return;
  del(root->lchild);
  del(root->rchild);
  delete root;
}

BTree::~BTree() { del(myRoot); }

void BTree::preorder(BinNode *root) {
  if (!root)
    return;
  std::cout << root->data;
  preorder(root->lchild);
  preorder(root->rchild);
}

void BTree::inorder(BinNode *root) {
  if (!root)
    return;
  inorder(root->lchild);
  std::cout << root->data;
  inorder(root->rchild);
}

void BTree::postorder(BinNode *root) {
  if (!root)
    return;
  postorder(root->lchild);
  postorder(root->rchild);
  std::cout << root->data;
}

void BTree::preorder_stack(BinNode *root) {
  std::stack<BinNode *> s;
  s.push(root);
  while (!s.empty()) {
    auto u = s.top();
    s.pop();
    if (!u)
      continue;
    std::cout << u->data;
    s.push(u->rchild);
    s.push(u->lchild);
  }
}

void BTree::inorder_stack(BinNode *root) {
  std::stack<BinNode *> s;
  auto u = root;
  while (u || !s.empty()) {
    while (u) {
      s.push(u);
      u = u->lchild;
    }
    u = s.top();
    s.pop();
    std::cout << u->data;
    u = u->rchild;
  }
}

void BTree::postorder_stack(BinNode *root) {
  std::stack<BinNode *> s;
  std::stack<BinNode *> ans;
  s.push(root);
  while (!s.empty()) {
    auto u = s.top();
    s.pop();
    if (!u)
      continue;
    ans.push(u);
    s.push(u->lchild);
    s.push(u->rchild);
  }
  while (!ans.empty()) {
    std::cout << ans.top()->data;
    ans.pop();
  }
}

void BTree::levelorder(BinNode *root) {
  std::queue<BinNode *> q;
  q.push(root);
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    if (!u)
      continue;
    std::cout << u->data;
    q.push(u->lchild);
    q.push(u->rchild);
  }
}

int BTree::levelX(BinNode *root, DataType x, int h) { return levelX(root, x); }

void BTree::KCount(BinNode *root, int h, int k, int &cnt) {
  cnt = KCount(root, k);
}

void BTree::graph(std::ostream &out) {
  std::vector<int> h(15), w(15);
  std::vector<std::vector<DataType>> a(2000, std::vector<DataType>(2000));
  std::vector<int> del(5000);

  h[1] = 1, h[2] = 2;
  w[1] = 0, w[2] = 1;

  for (int i = 3; i < 15; i++) {
    for (int j = 1; j < i; j++)
      h[i] += h[j];
  }

  auto check = [&](auto self, BinNode *u, int p) {
    if (!u) {
      del[p] = 1;
      return;
    }
    self(self, u->lchild, p << 1);
    self(self, u->rchild, p << 1 | 1);
  };
  check(check, myRoot, 1);

  auto dfs = [&](auto self, int x, int y, int n, int p, BinNode *rt) {
    if (!n || del[p])
      return;
    int l = p << 1, r = p << 1 | 1;
    a[x][y] = rt->data;
    for (int i = 0; i < h[n]; i++) {
      for (int j = 1; j <= h[n] - 1; j++)
        if (!del[l] && j == i)
          a[x + i][y - j] = '/';
      for (int j = 1; j <= h[n] - 1; j++)
        if (!del[r] && j == i)
          a[x + i][y + j] = '\\';
    }
    self(self, x + h[n], y - h[n], n - 1, l, rt->lchild);
    self(self, x + h[n], y + h[n], n - 1, r, rt->rchild);
  };
  int level = Height(myRoot);
  dfs(dfs, 0, h[level + 1] - 1, level, 1, myRoot);

  for (int i = 0; i < h[level + 1]; i++) {
    for (int j = 0; j < 2 * h[level + 1] - 1; j++)
      out << (a[i][j] ? a[i][j] : ' ');
    out << '\n';
  }
}

void graphAux(std::ostream &out, int indent, BinNode *root) {
  if (root) {
    graphAux(out, indent + 8, root->rchild);
    std::cout << std::setw(indent) << " " << root->data << '\n'; // 使用<iomanip>库
    graphAux(out, indent + 8, root->lchild);
  }
}

void test(BTree &t) {
  t.DisplayBTree();
  std::cout << "Is empty: " << (t.empty() ? "Yes" : "No") << '\n';
  std::cout << "Nodes: " << t.Nodes(t.myRoot) << '\n';
  std::cout << "Height: " << t.Height(t.myRoot) << '\n';
  std::cout << "Leaves: " << t.Leaves(t.myRoot) << '\n';
  std::cout << "levelX(A): " << t.levelX(t.myRoot, 'A') << '\n';
  std::cout << "levelX(E): " << t.levelX(t.myRoot, 'E') << '\n';
  std::cout << "levelX(H): " << t.levelX(t.myRoot, 'H') << '\n';
  std::cout << "KCount(2): " << t.KCount(t.myRoot, 2) << '\n';
  std::cout << "KCount(3): " << t.KCount(t.myRoot, 3) << '\n';
  std::cout << "KCount(4): " << t.KCount(t.myRoot, 4) << '\n';
  std::cout << '\n';
  graphAux(std::cout, 0, t.myRoot);
  std::cout << '\n';
  t.graph(std::cout);
}

int main() {
  std::vector<DataType> a = {'A', 'B', 'C', 'D', 0,   'E', 'F', 0,
                             'G', 0,   0,   'H', 'I', 0,   0};
  std::vector<DataType> b = {'A', 'B', 'C', 0, 'D', 'E', 'F', 0,
                             0,   'G', 0,   0, 'H', 0,   0};
  BTree ta(a), tb(b);
  test(ta);
  std::cout << '\n';
  test(tb);

  std::cout << "Copy Test\n";
  BTree c(a), d = b;
  test(c);
  std::cout << '\n';
  test(d);

  return 0;
}