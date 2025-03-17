class Solution {
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& visited,
             char initialColor, pair<int, int> currentNode,
             pair<int, int> prevNode, int level) {
        auto [row, col] = currentNode;
        visited[row][col] = 1;
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        for (int neighbour = 0; neighbour < 4; neighbour++) {
            int nRow = row + deltaRow[neighbour];
            int nCol = col + deltaCol[neighbour];

            if (nRow >= 0 and nRow < grid.size() and nCol >= 0 and
                nCol < grid[0].size() and grid[nRow][nCol] == initialColor) {
                if (!visited[nRow][nCol]) {
                    if (dfs(grid, visited, initialColor, {nRow, nCol},
                            currentNode, level + 1) == true) {
                        return true;
                    }

                } else if (visited[nRow][nCol] and
                           !(nRow == prevNode.first and
                             nCol == prevNode.second) and
                           level >= 4)
                       {
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

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!visited[row][col]) {

                    char initialColor = grid[row][col];
                    if (dfs(grid, visited, initialColor, {row, col}, {-1, -1},
                            1) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/**
check if visited
- no -> run dfs on same element (increase counter);
- yes -> check if same as prev element & count is 4 - yes return true;
- check all neighbours
 */