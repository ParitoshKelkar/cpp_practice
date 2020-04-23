class Solution {
  public:

    int getMaxWidth(TreeNode* root) {
      
      if (root == NULL)
        return 0;

      int max_width = 0;
      std::queue<TreeNode*> q; 
      q.push(root); 
      int level_width = q.size();
      while (!q.empty())
      {
        // q size is the size of the level 

        level_width = q.size();
        if (level_width > max_width)
          max_width = level_width;

        int temp = q.size();
        while (temp--)
        {
          TreeNode* temp_n = q.pop();
          if (temp_n->left)
            q.push_back(temp_n->left);
          if (temp_n->right)
            q.push_back(temp_n->right);
        }

      }
      return max_width;
    }



