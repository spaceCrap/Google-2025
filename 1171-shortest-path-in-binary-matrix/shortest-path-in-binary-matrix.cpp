class Solution {
public:
    // Using Dijkstra
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        // when src or dst is not 1
        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0) {
            return -1;
        }

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        queue < pair<int, pair<int, int>>> q;
        dist[0][0] = 0;
        // dist, {row,col}
        q.push({1, {0, 0}});

        int deltaRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int deltaCol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            int dis = q.front().first;
            auto [row, col] = q.front().second;

            q.pop();
            if(row == m-1 and col== n-1)
            {
                return dis;
            }
            

            for (int nbr = 0; nbr < 8; nbr++) {
                int nRow = row + deltaRow[nbr];
                int nCol = col + deltaCol[nbr];
                if(nRow>=0 and nRow<m and nCol>=0 and nCol<n and grid[nRow][nCol]==0
                and dist[nRow][nCol]>dis + 1)
                {
                     dist[nRow][nCol]=dis + 1;
                     q.push({dist[nRow][nCol],{nRow,nCol}});
                }
            }
        }
        return -1;
    }

    // Using BFS
    // int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    //     if (grid[0][0] != 0) {
    //         return -1;
    //     }
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     vector<vector<int>> visited(m, vector<int>(n, 0));

    //     queue<pair<int, pair<int, int>>> q;

    //     // row-1, col) ( row-1, col+1), (row,col+1), (row+1, col+1), (row+1,
    //     // col), (row+1, col-1), (row, col-1), (row-1, col-1)
    //     //

    //     int deltaRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    //     int deltaCol[] = {0, 1, 1, 1, 0, -1, -1, -1};

    //     visited[0][0] = 1;

    //     // dist , cord
    //     q.push({1, {0, 0}});

    //     while (!q.empty()) {
    //         int dist = q.front().first;
    //         auto [row, col] = q.front().second;
    //         q.pop();
    //           if (row == m - 1 && col == n - 1) {
    //                 return dist;
    //             }

    //         for (int nbr = 0; nbr < 8; nbr++) {
    //             int nRow = row + deltaRow[nbr];
    //             int nCol = col + deltaCol[nbr];

    //             if (nRow >= 0 and nRow < m and nCol >= 0 and nCol < n and
    //                 grid[nRow][nCol] == 0 and !visited[nRow][nCol]) {
    //                     visited[nRow][nCol]=1;
    //                     q.push({dist+1, {nRow,nCol}});
    //             }
    //         }
    //     }
    //     return -1;
    // }
};