class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> distanceResult(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    q.push({{row, col}, 0});
                    visited[row][col] = 0;
                }
            }
        }

        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            distanceResult[row][col] = distance;

            q.pop();
            for (int neighbour = 0; neighbour < 4; neighbour++) {
                int nRow = row + deltaRow[neighbour];
                int nCol = col + deltaCol[neighbour];

                if(nRow>=0 and nRow<m and nCol>=0 and nCol<n and
                grid[nRow][nCol]==1 and !visited[nRow][nCol])
                {
                    visited[nRow][nCol] = 1;
                    q.push({{nRow,nCol},distance+1});
                }
            }
        }
        return distanceResult;
    }
};