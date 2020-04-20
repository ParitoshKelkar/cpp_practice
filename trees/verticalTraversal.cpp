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
vector<vector<int>> verticalTraversal(TreeNode* root) {
    
    // declare map 
    std::map<int,vector<int>> hd_map; 
    
    //declare return value 
    vector<vector<int>> ans;
    
    // generate map 
    generateHorDist(0,root, hd_map);
    cout<<"Map Size "<<hd_map.size()<<"\n";
    
    // traverse,print and push into ans
    std::map<int, vector<int>>::iterator it;
    for (it = hd_map.begin(); it!=hd_map.end(); it++)
    {
        sort(it->second.begin(), it->second.end());
        ans.push_back(it->second);
        for (int i : it->second){
            cout<<i<<",";
        }
        cout<<"\n";
    }
    
    return ans;
        
    }

    void generateHorDist(int hd, TreeNode* root, std::map<int,vector<int>>& hd_map)
    {
        if(root == NULL)
            return;
        
       cout<<"Processing parent "<<root->val<<"\n";
        
        hd_map[hd].push_back(root->val);
        
        // left and right recurse 
        if (root->left)
        {
            generateHorDist(hd-1, root->left, hd_map);
 //           cout<<"Processing left of parent "<<root->val<<"\n";
        }
        if (root->right)
        {
            generateHorDist(hd+1, root->right, hd_map);
//            cout<<"Processing right of parent "<<root->val<<"\n";
        }
    }
};
