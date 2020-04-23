/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        std::map<int, vector<long long unsigned int>> depth_map;
        long long unsigned int pos = 1;
        int depth = 1; //root level is 1 not 0
        populateMap(root, depth_map, pos, depth);
        
        std::cout<<"The size of the depth map is "<<depth_map.size()<<"\n";
        
        vector<int> width_vec;
        // at each depth, calculate width 
        map<int,vector<long long unsigned int>>::iterator it;
        for (it = depth_map.begin(); it != depth_map.end(); it++)
        {
            int temp_max = *max_element(it->second.begin(), it->second.end());
            int temp_min = *min_element(it->second.begin(), it->second.end());
            width_vec.push_back(temp_max-temp_min);
        }
        return (int)*max_element(width_vec.begin(), width_vec.end())+1;
        
    }
    
    void populateMap(TreeNode* root, map<int, vector<long long unsigned int>>& depth_map, long long unsigned int pos, int depth)
    {
        if (root!=NULL)
        {
            depth_map[depth].push_back(pos);
            populateMap(root->left, depth_map, 2*pos, depth+1);
            populateMap(root->right, depth_map, 2*pos+1, depth+1);
        }
    }
};
