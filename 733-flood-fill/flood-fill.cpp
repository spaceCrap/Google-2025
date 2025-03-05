class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited,
             int initialColor, int color, int row, int col, int& m, int& n) {
        visited[row][col] = color;
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + deltaRow[i];
            int nCol = col + deltaCol[i];
            if (nRow >= 0 and nRow < m and nCol >= 0 and nCol < n and
                graph[nRow][nCol] == initialColor and
                visited[nRow][nCol] != color) {
                dfs(graph, visited, initialColor, color, nRow, nCol, m, n);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& graph, int sr, int sc,
                                  int color) {
        vector<vector<int>> visited = graph;
        int m = graph.size();
        int n = graph[0].size();
        int initialColor = graph[sr][sc];
        dfs(graph, visited, initialColor, color, sr, sc, m, n);
        return visited;
    }
};