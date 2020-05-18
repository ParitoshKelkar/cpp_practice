class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {

      //  if (n == 0)
           // return NULL;

        int start = 0;
        int end = n;
        vector<TreeNode*> ans =  construct(start, end);
        cout<<ans.size()<<"\n";
        return ans;
    };

    vector<TreeNode*> construct(int start, int end)
    {
        vector<TreeNode*> net_trees;
        if (start > end){
            net_trees.push_back(NULL);
            return net_trees;
        }

        for (int root_iter = 1; root_iter <=end; root_iter++)
        {
            // each val will be root once
            // for each root, construct the different subtrees
           vector<TreeNode*> left_subtrees = construct(1, root_iter-1);
           vector<TreeNode*> right_subtrees = construct(root_iter+1, end);

            for (auto left_node : left_subtrees)
            {
                for (auto right_node: right_subtrees){
                   TreeNode* temp_n = new TreeNode(root_iter, left_node, right_node);
                    net_trees.push_back(temp_n);
                }
            }
        }
        return net_trees;
    }
};
