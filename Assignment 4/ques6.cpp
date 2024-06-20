# include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool check_isomorphic(TreeNode* n1, TreeNode* n2) {
    if (n1 == nullptr && n2 == nullptr) return true;
    if (n1 == nullptr || n2 == nullptr) return false;
    return check_isomorphic(n1->left, n2->left) && check_isomorphic(n1->right, n2->right);
}