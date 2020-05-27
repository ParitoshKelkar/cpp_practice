struct comp{
    bool operator()(pair<int,pair<int,int> > &p1,pair<int,pair<int,int> > &p2){
        return p1.first>p2.first;
    }
};
 class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > ans;
     map<pair<int,int>,int> m;
        int n=nums1.size();
        int mm=nums2.size();
        if(n==0 || mm==0){
            return ans;
        }
        int i=0,j=0;
        m[{0,0}]=1;
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,comp> pq;
        pq.push({nums1[i]+nums2[j],{0,0}});
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            i=t.second.first;
            j=t.second.second;
            ans.push_back({nums1[i],nums2[j]});
            k--;
            if(k==0) break;
            if(i+1<n && m[{i+1,j}]==0){
                m[{i+1,j}]=1;
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
            }
            if(j+1<mm && m[{i,j+1}]==0){
                m[{i,j+1}]=1;
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return ans;
    }
};
