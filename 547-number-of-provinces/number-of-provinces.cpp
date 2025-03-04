class Solution {
private:
    void dfs(unordered_map<int, vector<int>>& graph, vector<int>& visited,
             int& node) {
        visited[node] = 1;
        for (auto& neighbour : graph[node]) {
            if (!visited[neighbour]) {
                dfs(graph, visited, neighbour);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinceCount = 0;

        unordered_map<int, vector<int>> adjacencyList(n);
        vector<int> visited(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] != 0 && i != j) {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }

        for (int node = 0; node < n; node++) {
            
            if (!visited[node]) {
                provinceCount++;
                dfs(adjacencyList, visited, node);
            }
        }

        return provinceCount;
    }
};