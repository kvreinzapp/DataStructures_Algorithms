/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int depth = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int count = q.size();
      while (count > 0) {
        TreeNode *curr = q.front();
        q.pop();
        if (curr->left != NULL)
          q.push(curr->left);
        if (curr->right != NULL)
          q.push(curr->right);
        count--;
      }
      depth++;
    }
    return depth;
  }
};
