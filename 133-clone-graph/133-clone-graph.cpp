class Solution {
public:
    map<Node *,Node *> mp;
    Node* cloneGraph(Node* node) 
    {
        if(!node) return node;
        
        Node *ans = new Node(node->val,{});
        mp[node] = ans;
        queue<Node*> q;
        q.push(node);
        
        while(q.size())
        {
            Node *f = q.front();
            q.pop();
            
            for(auto it: f->neighbors)
            {
                if(mp.find(it)==mp.end())
                {
                    mp[it] = new Node(it->val,{});
                    q.push(it);
                }
                mp[f]->neighbors.push_back(mp[it]);
            }
        }
        return ans;
    }
};