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
    int sumNumbers(TreeNode* root) {
       vector<vector<int>> all_paths;
       vector<int> cur_path; 
        
        // get all paths 
       traverse(root, all_paths, cur_path);
        
        // iterate through all paths and calc sum 
        int ans_sum = 0;
        for (auto path:all_paths)
        {
            reverse(path.begin(), path.end());
            int path_sum = 0;
            int base_iter  = 0;
            for (auto num:path){
                path_sum+=num*pow(10,base_iter);
                base_iter++;
            }
            ans_sum+=path_sum;
        }
        return ans_sum;
    }
    
    void traverse(TreeNode* root, vector<vector<int>>& all_paths, vector<int> cur_path)
    {
        if (root == NULL)
            return;
        
        cur_path.push_back(root->val);
        if (root->left)
            traverse(root->left, all_paths, cur_path);
        
        if (root->right)
            traverse(root->right, all_paths, cur_path);
        
        if (!root->left && !root->right)
        {
            // its  a leaf 
            all_paths.push_back(cur_path);
            return;
        }
        return;
    }
};
