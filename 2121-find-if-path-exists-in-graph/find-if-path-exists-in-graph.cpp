class Solution {
public:

//  bool bfs(int source, int destination,
//              unordered_map<int, vector<int>>& graph, int n) {
//         bool pathExist = false;
//         vector<int> visited(n + 1);
//         queue<int> q;
//         q.push(source);
//         visited[source] = 1;

//         while (!q.empty()) {
//             int node = q.front();
//             vector<int>& neighbours = graph[node];
//             q.pop();

//             for (int neighbourNode : neighbours) {
//                 if (neighbourNode == destination) {
//                     return pathExist = true;
//                 }
//                 if (!visited[neighbourNode]) {
//                     visited[neighbourNode] = 1;
//                     q.push(neighbourNode);
//                 }
//             }
//         }
//         return pathExist;
//     }

   void dfs(int& node, unordered_map<int,vector<int>>& graph, int& destination, bool& isPathExist, vector<int>& visited)
    {
        if(destination == node)
        {
            isPathExist=true;
        }
        visited[node]=1;
        for(auto& neighbour : graph[node])
        {
            if(isPathExist)
            {
                return;
            }
            if(!visited[neighbour])
            {
                dfs(neighbour, graph, destination, isPathExist, visited );
            }
            
        }

        
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
        {
            return true;
        }

        bool isPathExist = false;
        unordered_map<int,vector<int>> graph;
        vector<int> visited(n);
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b=edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(source, graph,destination, isPathExist,visited);

        return isPathExist;
        // return bfs(source, destination, graph, n);
    }
};