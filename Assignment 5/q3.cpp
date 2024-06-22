#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <utility>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void makeMapping(map<TreeNode*, TreeNode*>& parent, TreeNode* root, TreeNode*& target, int t) {
    if (root == NULL) return;
    if (root->val == t) target = root;
    if (root->left) {
        parent[root->left] = root;
        makeMapping(parent, root->left, target, t);
    }
    if (root->right) {
        parent[root->right] = root;
        makeMapping(parent, root->right, target, t);
    }
}

void traverse(TreeNode* start, map<TreeNode*, TreeNode*>& parent, int s, TreeNode* prev, int mn, int mx, int sum, vector<int>& ans) {
    if (start == NULL) return;

    if (start->val == s) {
        mn = min(mn, start->val);
        mx = max(mx, start->val);
        sum += start->val;
        ans.push_back(mn);
        ans.push_back(mx);
        ans.push_back(sum);
        return;
    }

    if (start->left != prev)
        traverse(start->left, parent, s, start, min(mn, start->val), max(mx, start->val), sum + start->val, ans);
    if (start->right != prev)
        traverse(start->right, parent, s, start, min(mn, start->val), max(mx, start->val), sum + start->val, ans);
    if (parent[start] != prev)
        traverse(parent[start], parent, s, start, min(mn, start->val), max(mx, start->val), sum + start->val, ans);
}

vector<int> solve(pair<int, int> p, TreeNode* root) {
    map<TreeNode*, TreeNode*> parent;
    parent[root] = NULL;
    TreeNode* target = NULL;
    TreeNode* prev = NULL;
    makeMapping(parent, root, target, p.first);
    vector<int> v;
    traverse(target, parent, p.second, prev, INT_MAX, INT_MIN, 0, v);
    return v;
}

vector<vector<int> > TreePathQueries(vector<pair<int, int> > p, TreeNode* root) {
    vector<vector<int> > answer;
    for (vector<pair<int, int> >::iterator it = p.begin(); it != p.end(); ++it) {
        vector<int> a = solve(*it, root);
        answer.push_back(a);
    }
    return answer;
}

int main() {
    // use the function TreePathQueries
    return 0;
}