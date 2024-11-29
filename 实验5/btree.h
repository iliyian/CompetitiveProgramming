#include <vector>
#include <iostream>

#define DataType char

typedef char Datatype; // 测试使用可以使用char或者int对应DataType
class BinNode {
public:
  BinNode() : lchild(0), rchild(0) {}
  BinNode(DataType d) : data(d), lchild(0), rchild(0) {}
  DataType data;   // 数据
  BinNode *lchild; // 左子树指针
  BinNode *rchild; // 右子树指针
}; // 课本DataType 为char

// 二叉树类的设计：
class BTree {
public:
  BTree(); // 构造1 空树构造
  BTree(const std::vector<DataType> &init);
  BinNode *build(const std::vector<DataType> &init, int pos);
  BTree(const BTree &other);
  BTree &operator=(const BTree &other);
  // BTree(?); //构造2 CreateBTree
  // 构造2:可以考虑使用BTree(const vector<DataType>& init);
  // 或DataType参考课本为char则也可以使用BTree(const string& init); 这样的形式
  // 或者在无参构造中采用输入树结点序列的策略来构造一棵带若干结点的//二叉树。
  // 可参考课件和课本中二叉树构造的方法：p228, p240 7.13, p260,p262
  bool empty();        // 判空
  void DisplayBTree(); // 二叉树遍历，调用遍历相关的辅助函数
  BinNode *FindNode(BinNode *root, const DataType &x) const; // 查找 参考p230
  int Nodes(BinNode *root);                                // 求树结点总数 参考p234 例7.9
  int Height(BinNode *root);                               // 求树高 参考p230
  int Leaves(BinNode *root);                               // 求叶子数 参考课件
  void displayLeaves(BinNode *root);                       // 从左到右输出叶子，参考p236 7.10
  int levelX(BinNode *root, DataType x);                     // 计算x在第几层? 参考p239 7.12
  int KCount(BinNode *root, int k);                          // 计算k层的结点数 参考p241 7.14
  void graph(std::ostream &out);
  ~BTree(); // 销毁二叉树 DestroyBTree 参考p231
private:
  BinNode *myRoot; // 树根指针
  // 其他辅助函数
  void preorder(BinNode *root);        // 先序遍历
  void preorder_stack(BinNode *root);  // 使用栈的非递归先序遍历
  void inorder(BinNode *root);         // 中序遍历
  void inorder_stack(BinNode *root);   // 使用栈的非递归中序遍历
  void postorder(BinNode *root);       // 后序遍历
  void postorder_stack(BinNode *root); // 使用栈的非递归后序遍历
  void levelorder(BinNode *root);      // 层次遍历

  BinNode *FindNode(BinNode *root, DataType x);           // 查找x
  int levelX(BinNode *root, DataType x, int h);       // 计算x在第几层？
  void KCount(BinNode *root, int h, int k, int &cnt); // 计算k层结点数

  friend void test(BTree &t);
  void copy(BinNode *root, BinNode *&rt);
};

