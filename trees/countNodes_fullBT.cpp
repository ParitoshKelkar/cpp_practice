class Solution {
public:
    int countNodes(TreeNode* root) {
        
        if (root == NULL)
            return 0;

        int left_depth=1; int right_depth =1;
        if (root->left)
            left_depth = getLeftDepth(root->left);
        if (root->right)
            right_depth = getRightDepth(root->right);
        
        cout<<"Left Depth "<<left_depth<<"; Right Depth "<<right_depth<<"\n";
        
        if (left_depth == right_depth)
            return pow(2,left_depth)-1;
        
        return countNodes(root->left) + countNodes(root->right)+1;
        
    }
    
    int getLeftDepth(TreeNode* root)
    {
        int count = 1;
        while (root)
        {
            count+=1;
            root = root->left;
        }
        return count;
    }
    
    int getRightDepth(TreeNode* root)
    {
        int count = 1;
        while (root)
        {
            count+=1;
            root = root->right;
        }
        return count;
    }
};
