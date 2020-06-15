class Solution {
 public:
  bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    bool result = false;
    if (pRoot1 == NULL || pRoot2 == NULL)
      return false;
    if (pRoot1->val == pRoot2->val)
      result = fangwen(pRoot1, pRoot2);
    if (!result)
      result = HasSubtree(pRoot1->left, pRoot2);
    if (!result)
      result = HasSubtree(pRoot1->right, pRoot2);
    return result;
  }
  bool fangwen(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot2 == NULL)
      return true;
    if (pRoot1 == NULL)
      return false;
    if (pRoot1->val != pRoot2->val)
      return false;
    return fangwen(pRoot1->left, pRoot2->left) &&
           fangwen(pRoot1->right, pRoot2->right);
  }
};
