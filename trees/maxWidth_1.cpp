class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        std::map<int, vector<int>> depth_map;
        int x_offset = 0;
        int depth = 1; //root level is 1 not 0
        populateMap(root, depth_map, x_offset, depth);
        
        std::cout<<"The size of the depth map is "<<depth_map.size()<<"\n";
        
        vector<int> width_vec;
        // at each depth, calculate width 
        map<int,vector<int>>::iterator it;
        for (it = depth_map.begin(); it != depth_map.end(); it++)
        {
            int temp_max = *max_element(it->second.begin(), it->second.end());
            int temp_min = *min_element(it->second.begin(), it->second.end());
            width_vec.push_back(temp_max-temp_min);
        }
        return *max_element(width_vec.begin(), width_vec.end());
        
    }
    
    void populateMap(TreeNode* root, map<int, vector<int>>& depth_map, int x_offset, int depth)
    {
        if (root!=NULL)
        {
            depth_map[depth].push_back(x_offset);
            populateMap(root->left, depth_map, x_offset-1, depth+1);
            populateMap(root->right, depth_map, x_offset+1, depth+1);
        }
    }
};
