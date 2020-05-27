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
    void flatten(TreeNode* root) {
        TreeNode* ans = recurse(root);
    }
    
    TreeNode* recurse(TreeNode* root)
    {
        if (root == NULL)
            return NULL;
        
        TreeNode* temp_left = NULL;
        TreeNode* temp_right = NULL;
       
        if (!root->left && !root->right){
            cout<<"returning ptr for "<<root->val<<"\n"; 
            return root;
        }
        
        cout<<"Not leaf "<<root->val<<"\n";
        
        if (root->left){
            temp_left = recurse(root->left);
            cout<<"temp left "<<temp_left->val<<"\n";
        }
        
        if (root->right)
            temp_right = recurse(root->right);
            
        
        if (temp_left!=NULL && temp_right!=NULL) // recived valid leaf from each side 
        {
            cout<<"entering rearrangement for "<<root->val<<"\n";
            root->left = NULL;
            root->right = temp_left; 
            
            // iterate to leaf of temp_left 
            while (temp_left->right)
                temp_left = temp_left->right;
            
            temp_left->right = temp_right;
        }
        
        else if (temp_left && !temp_right)
        {
            root->left = NULL;
            root->right = temp_left;
        }
        
        return root;
    }
};
