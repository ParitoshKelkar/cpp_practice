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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
      map<int, vector<vector<int>>> sum_map; 
      vector<int> current_path;
      int cur_sum = 0;
      
      recurse(root, current_path, cur_sum, sum_map,sum);
      return sum_map[sum];
    }
  
  
    void recurse(TreeNode* root, vector<int> current_path, int cur_sum, map<int, vector<vector<int>>>&sum_map, int target_sum)
    {
      if (root == NULL)
        return;
      
      cur_sum+=root->val;
      current_path.push_back(root->val);
      if (cur_sum == target_sum) //dont do anything if its not a leaf
      {
        if (root->left == NULL && root->right == NULL)
        {
          // if key exists, add to vector<vector<int>> 
          // if new key, create vector<vector<int>> and add value 
          if (sum_map.find(cur_sum)!=sum_map.end()) //key exists
          {
            vector<vector<int>> temp =  sum_map[cur_sum];
            temp.push_back(current_path);
            sum_map[cur_sum]=temp;
          }
          else
          {
            vector<vector<int>> temp; 
            temp.push_back(current_path);
            sum_map[cur_sum] = temp;
          }
          
          return;
        }
      }
      
      // keep going until leaf to confirm final sum 
      if (root->left)
        recurse(root->left, current_path, cur_sum, sum_map, target_sum);
      
      if (root->right)
        recurse(root->right, current_path, cur_sum, sum_map, target_sum);
        
        return;
    }
};
