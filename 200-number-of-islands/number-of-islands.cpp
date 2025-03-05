class Solution {
private:
    void dfs(vector<vector<char>>& graph, vector<vector<int>>& visited, int row,
             int col, int m, int n) {
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        visited[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];
            if (nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and
                graph[nrow][ncol] == '1' && visited[nrow][ncol] != 1) {
                dfs(graph, visited, nrow, ncol, m, n);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& graph) {
        int m = graph.size();
        int n = graph[0].size();
        int counter = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!visited[row][col] && graph[row][col] == '1') {
                    dfs(graph, visited, row, col, m, n);
                    counter++;
                }
            }
        }
        return counter;
    }
};