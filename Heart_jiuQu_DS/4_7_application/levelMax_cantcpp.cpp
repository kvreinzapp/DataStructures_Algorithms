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
  vector<int> largestValues(TreeNode *root) {
    if (root == NULL)
      return {};
    vector<int> ret;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int count = q.size();
      int level_max = 0x80000000;
      while (count > 0) {
        TreeNode *curr = q.front();
        q.pop();
        if (level_max < curr->val)
          level_max = curr->val;
        if (curr->left != NULL)
          q.push(curr->left);
        if (curr->right != NULL)
          q.push(curr->right);
        count--;
      }
      ret.push_back(level_max);
    }
    return ret;
  }
};
