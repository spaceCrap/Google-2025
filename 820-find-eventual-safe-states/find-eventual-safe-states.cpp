class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> reverseList;
        int n = graph.size();
        vector<int> indegree(n,0);
         queue<int> q;
         vector<int> result;
        
        for(int i=0;i<n;i++)
        {

           for(auto neighbour: graph[i])
           {
            reverseList[neighbour].push_back(i);
            indegree[i]++;
           }
        }

       
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(auto& neighbour: reverseList[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                {
                    q.push(neighbour);
                }
            }
        }

        sort(result.begin(),result.end());
        return result;
        
    }
};