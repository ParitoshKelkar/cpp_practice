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

// PostOrder: L R Rt
// InOrder:   L Rt R
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      // the post order wil contain root at the end 
      
      if (inorder.size() == 0 || postorder.size() == 0)
        return NULL;
      
      TreeNode* root = new TreeNode();
      root->val = postorder.back(); // last element will be root 
      // remove root val from vector; given that no unique elements are present 
      postorder.erase(postorder.end()-1);
      
      // from inorder. get left and right elements 
      vector<int>::iterator it_root = find(inorder.begin(), inorder.end(), root->val);
      if (it_root-1 - inorder.begin() >= 0){
        vector<int>::iterator first = inorder.begin(); 
        vector<int>::iterator last = inorder.begin() + distance(inorder.begin(), it_root);
      vector<int> new_left_subtree_inorder(first, last);
        
      vector<int> new_post;
      for (auto el : postorder)
      {
        if (find(new_left_subtree_inorder.begin(), new_left_subtree_inorder.end(), el)!= new_left_subtree_inorder.end())
          new_post.push_back(el);
          
      }
      root->left = buildTree(new_left_subtree_inorder, new_post);
      }
  //    cout<<"Left Subtrees found for  "<<root->val<<"\n";
      if (inorder.end() - it_root+1 >= 0){
        vector<int> new_right_subtree_inorder(it_root+1, inorder.end());
        vector<int> new_post;
        for (auto el : postorder)
        {
          if (find(new_right_subtree_inorder.begin(), new_right_subtree_inorder.end(), el)!= new_right_subtree_inorder.end())
            new_post.push_back(el);

        }
        root->right = buildTree(new_right_subtree_inorder, new_post);
      }
   //   cout<<"Right Subtrees found for  "<<root->val<<"\n";
      
      
      return root;
      
    }
  
};

