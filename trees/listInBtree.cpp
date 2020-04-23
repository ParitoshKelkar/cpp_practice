class Solution {
public:
    
    bool isSubPathUtil(ListNode* head, TreeNode* root){
        
        if(head == NULL){
            return true;
        }
        
        if(root == NULL)
            return false;
        
        bool c = false;
        if(root->val == head->val){
            head = head->next;
            c = true;
        }
        
        bool a = isSubPathUtil(head, root->left);
        bool b = isSubPathUtil(head, root->right);
        
        return c&&(a || b);
        
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == NULL)
            return true;
        if(root == NULL)
            return false;
        return isSubPathUtil(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right); 
    }
};
