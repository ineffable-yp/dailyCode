#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Tree
{
public:
    Tree(int num);
    Tree(TreeNode *r = nullptr) : root(r) {}
    ~Tree();
    void addNode(int i, int j);
    void addBroNode(TreeNode *localRoot, TreeNode *node);

private:
    TreeNode *root;
};
//为节点分配空间
Tree::Tree(int num)
{
    root = new TreeNode[num];
    for (int i = 0; i < num; i++)
    {
        root[i].left = nullptr;
        root[i].right = nullptr;
        root[i].val = 0;
    }
}
//释放空间
Tree::~Tree()
{
    if (nullptr != root)
        delete[] root;
}
void Tree::addNode(int rooti, int nodej)
{
    TreeNode *rootI = &root[rooti];
    TreeNode *nodeJ = &root[nodej];

    if (rootI->left == nullptr)
        rootI->left = nodeJ;
    else //搜索右子树
        addBroNode(rootI->left, nodeJ);
}
void Tree::addBroNode(TreeNode *localroot, TreeNode *node)
{
    if (localroot->right == nullptr)
        localroot->right = node;
    else
        addBroNode(localroot->right, node);
}
int main()
{
    return 0;
}