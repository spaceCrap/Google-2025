class Solution {

    private: 
    void dfs(unordered_map<int,vector<int>>& graph, vector<int>& visited, int source, int& result)
    {
        visited[source] =1;

        for(auto neighbour : graph[source])
        {
            if(!visited[abs(neighbour)])
            {
                if(neighbour>0)  // forward path is there (0 to 1) but we need negative (1 to 0 = so add)
                {
                    result++;
                }
                dfs(graph, visited, abs(neighbour), result);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int result = 0;
        unordered_map<int,vector<int>> graph;
        vector<int> visited(n,0);

        for(int i=0;i<connections.size();i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            graph[a].push_back(b);
            graph[b].push_back(-a);
        }

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(graph, visited, i, result);
            }
        }
        return result;

        
    }
};