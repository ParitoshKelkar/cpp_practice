/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
      
      map<unsigned int, string> sum_string;
      unsigned int current_sum = 0.0;
      
      string path("");
      if (root == NULL) return "";
      
      process(root, sum_string, current_sum, path);
      
      string ans_flip =  sum_string.begin()->second;
      reverse(ans_flip.begin(), ans_flip.end());
      return ans_flip;
    }
  
  void process(TreeNode* root, map<unsigned int, string>& sum_string, unsigned int current_sum, string path)
  {
    if (root == NULL)
      return;
    
    current_sum+=root->val;
    path.append(getStringFromVal(root->val));
    // if root == leaf 
    if (root->left == NULL && root->right == NULL)
    {
      sum_string[current_sum]=path;
      return;
    }
    
    // left subtree
    if (root->left)
      process(root->left, sum_string, current_sum, path);
    
    // right
    if (root->right)
      process(root->right, sum_string, current_sum, path);
  }
  
  string getStringFromVal(int val)
  {
    // 97  = 'a' 
    string s(1,char(97 + val));
    return s;
  }
};
