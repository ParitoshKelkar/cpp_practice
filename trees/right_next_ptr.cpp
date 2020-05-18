class Solution {
public:
    Node* connect(Node* root){
        if (root == NULL)
            return NULL;

    queue<Node*> q;
    q.push(root);
    unordered_map<int,std::vector<Node*>> depth_map;
    int depth_level = 0;
    // breadth first search to figure out depth map
    while (!q.empty())
    {
        Node* current_node = q.front();
        q.pop();
        depth_map[depth_level].push_back(current_node);
        if (current_node->left){
            q.push(current_node->left);
            q.push(current_node->right);
            depth_level+=1;
        }

    }

    cout<<"depth map size "<<depth_map.size()<<"\n";
    cout<<"First element depth map "<<depth_map[0][0]->val<<"\n";
    for (auto it = depth_map.begin(); it!=depth_map.end(); it++)
    {
        int temp_i =0;
        cout<<"IT element depth map "<<it->second[0]->val<<"\n";
        for (int temp_i =0; temp_i<it->second.size()-1; temp_i++){
            it->second[temp_i]->next = it->second[temp_i+1];
            cout<<"Connecting "<<it->second[temp_i]->val<<" with "<<it->second[temp_i+1]->val<<"\n";
        }

        it->second[temp_i] = NULL;
    }

    cout<<"First element depth map "<<depth_map[0][0]->val<<"\n";
    return depth_map[0][0];
    }
};
