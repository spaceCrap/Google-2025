class Solution {
    typedef pair<int,int> pint;
public:
// 1,1,1,2,2,3], k = 2
// 1->3 
// 2->2
// 3->1
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int> mp;
        priority_queue<pint, vector<pint>, greater<pint>> pq;
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

          for(auto& item: mp)
        {
            int element = item.first;
            int freq = item.second;
             pq.push({freq,element});
            if(pq.size()>k)
            {
                pq.pop();
            }
           
        }
        while(pq.size())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};