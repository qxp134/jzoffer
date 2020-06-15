/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
    if (pre.size() == NULL)
      return NULL;
    TreeNode* root = new TreeNode(pre[0]);
    int i;
    for (i = 0; i < in.size() && in[i] != pre[0]; i++)
      ;
    vector<int> pre_left, in_left, pre_right, in_right;
    int pre_i = 1;
    for (int j = 0; j < in.size(); j++) {
      if (j < i) {
        in_left.push_back(in[j]);
        pre_left.push_back(pre[pre_i]);
        pre_i++;
      } else if (j > i) {
        in_right.push_back(in[j]);
        pre_right.push_back(pre[pre_i]);
        pre_i++;
      }
    }
    root->left = reConstructBinaryTree(pre_left, in_left);
    root->right = reConstructBinaryTree(pre_right, in_right);
    return root;
  }
};
