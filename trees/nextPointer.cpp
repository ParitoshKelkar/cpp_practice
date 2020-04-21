class Solution {
public:
    Node* connect(Node* root) {
        
        std::unordered_map<int,vector<Node*>> depth_map;
        int cur_depth = 0;
        getDepthMap(depth_map, root, cur_depth);
       
        //size of depthmap 
        cout<<"The size of map is "<<depth_map.size()<<"\n";
        
        // iterate and fill 
        std::unordered_map<int, vector<Node*>>::iterator it;
        for (it = depth_map.begin(); it!= depth_map.end(); ++it)
        {
           Node* n = it->second[0];
           for (int i = 1; i < it->second.size(); i++)
           {
               cout<<"Processing root "<<n->val<<"\n";
               n->next = it->second[i];
               n = it->second[i];
           }
           n->next = NULL;
        }
        
        return root;
    }
    
    void getDepthMap(std::unordered_map<int,vector<Node*>>& depth_map, Node* root, int cur_depth)
    {
        if (root == NULL)
            return;
       
        depth_map[cur_depth].push_back(root);
        if (root->left)
            getDepthMap(depth_map, root->left, cur_depth+1);
        if (root->right)
            getDepthMap(depth_map, root->right, cur_depth+1);
    }
};
