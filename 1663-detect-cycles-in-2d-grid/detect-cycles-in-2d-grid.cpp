class Solution {

private:
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& visited,
             int level, int row, int col, pair<int, int> prevCord) {
        char currentVal = grid[row][col];
        visited[row][col] = 1;
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + deltaRow[i];
            int nCol = col + deltaCol[i];

            if (nRow >= 0 and nRow < grid.size() and nCol >= 0 and
                nCol < grid[0].size() && grid[nRow][nCol] == currentVal) {
                if (visited[nRow][nCol] != 1) {
                    if (dfs(grid, visited, level + 1, nRow, nCol, {row, col}) ==
                        true) {
                        return true;
                    }
                  
                } else if (visited[nRow][nCol] == 1 and
                           !(nRow == prevCord.first &&
                             nCol == prevCord.second) and
                           level >= 4) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {

                    if (dfs(grid, visited, 1, i, j, {-1, -1}) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
