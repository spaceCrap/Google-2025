class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<pair<int, int>>& visitedWithSet,
             int node) {
        auto [visited, set] = visitedWithSet[node];
        for (auto neighbour : graph[node]) {
            auto [nVisited, nSet] = visitedWithSet[neighbour];
            if (!nVisited) {
                visitedWithSet[neighbour] = {1, !set};
                if (dfs(graph, visitedWithSet, neighbour) == false)
                    return false;
            } else if (nVisited && nSet == set) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<pair<int, int>> visitedWithSet(n, {0, 0});
        for (int i = 0; i < n; i++) {
            auto [visited, belongingSet] = visitedWithSet[i];
            if (!visited) {
                if (dfs(graph, visitedWithSet, i) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};