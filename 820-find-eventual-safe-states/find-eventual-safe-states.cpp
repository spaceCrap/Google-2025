class Solution {

    private:
    bool dfs(vector<vector<int>>& graph,  vector<int>& visited,
      vector<int>& pathVisited, int node)
      {
        visited[node] =1;
        pathVisited[node]=1;

        for(auto& neighbour: graph[node])
        {
            if(!visited[neighbour])
            {
                if(dfs(graph,visited,pathVisited, neighbour)==false)
                {
                    return false;
                }
            }
            else if(visited[neighbour] && pathVisited[neighbour])
            {
                return false;
            }
        }
        pathVisited[node]=0;
        return true;
      }
     
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> pathVisited(n,0);
        vector<int> result;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(graph, visited, pathVisited, i);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(pathVisited[i]==0)
            {
                result.push_back(i);
            }
        }

        return result;
        
    }
};