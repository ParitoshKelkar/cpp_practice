class Solution {
public:
 const int mod = 1000000007;
    
    int getSum(TreeNode *node) {
        if (!node) return 0;
        
        return node->val + getSum(node->left) + getSum(node->right);
    }
    
    long long getmaxProd(TreeNode *node, const int totalSum, long long &maxProd) {
        if (!node) return 0;
        
        int left = getmaxProd(node->left, totalSum, maxProd);
        int right = getmaxProd(node->right, totalSum, maxProd);
        int sum = node->val + left + right;
        
        long long currProd = (long long)sum * (totalSum - sum); // DON'T DO THE MOD HERE!
        maxProd = max(maxProd, currProd);
        
        return sum;
    }
    
    int maxProduct(TreeNode* root) {
        if (!root) return 0;
        
        long long maxProd = 0;
        const int totalSum = getSum(root);
        
        getmaxProd(root, totalSum, maxProd);
        
        return maxProd % mod; // JUST DO MOD OF THE FINAL ANSWER
    }
};
