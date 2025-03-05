class Solution {
private:
    void dfs(vector<vector<int>>& graph, int initialColor, int color, int row,
             int col) {
        graph[row][col] = color;
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + deltaRow[i];
            int nCol = col + deltaCol[i];
            if (nRow >= 0 and nRow < graph.size() and nCol >= 0 and
                nCol < graph[0].size() and graph[nRow][nCol] == initialColor and
                graph[nRow][nCol] != color) {
                dfs(graph, initialColor, color, nRow, nCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& graph, int sr, int sc,
                                  int color) {

        int initialColor = graph[sr][sc];
        dfs(graph, initialColor, color, sr, sc);
        return graph;
    }
};