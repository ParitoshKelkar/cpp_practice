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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
      // bfs for generating level order 
      // vector<vector>> storage 
      // zig-zag during iter? while performing bfs 
      
      vector<vector<int>> lot; 
      queue<TreeNode*> q; 
      q.push(root);
      if (!root)
        return lot;
      
      int cur_iter = 1;
      vector<TreeNode*> temp_stack_ptr; 
      vector<int> temp_stack_val; 
      bool left_to_right = true;
      while (!q.empty())
      {
        while (cur_iter)
        {
          temp_stack_ptr.push_back(q.front());
          temp_stack_val.push_back(q.front()->val);
          q.pop();
          cur_iter--;
        }
        for (auto el:temp_stack_ptr)
        {
          if (el->left){
            q.push(el->left);
            cur_iter++;
          }
          if (el->right){
            q.push(el->right);
            cur_iter++;
          }
        }
        if (!left_to_right){
          reverse(temp_stack_val.begin(), temp_stack_val.end());
        }
        left_to_right = !left_to_right;
        
        lot.push_back(temp_stack_val);
        temp_stack_val.clear();
        temp_stack_ptr.clear();
      }
      return lot;
    }
};
