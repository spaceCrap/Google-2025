class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rottenTime = 0;
        int freshOrange = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited = grid;
        queue<pair<pair<int, int>, int>> rottenQ;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    rottenQ.push({{i, j}, 0});
                } else if(grid[i][j]==1) {
                    freshOrange++;
                }
            }
        }
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        //[  {{0,0},0} , {{2,2},0}]

        while (!rottenQ.empty()) {
            int row = rottenQ.front().first.first;
            int col = rottenQ.front().first.second;
            int time = rottenQ.front().second;
            rottenQ.pop();

            for (int i = 0; i < 4; i++) {
                int nRow = row + deltaRow[i];
                int nCol = col + deltaCol[i];

                if (nRow >= 0 and nRow < m and nCol >= 0 and nCol < n and
                    grid[nRow][nCol] == 1 and visited[nRow][nCol] != 2) {
                        freshOrange--;
                        rottenQ.push({{nRow,nCol},time+1});
                        rottenTime = max(rottenTime, time+1);
                        visited[nRow][nCol] = 2;
                }

            }
        }
        if(freshOrange>0)
        {
            cout<<freshOrange<<" fresh"<<endl;
            return -1;
        }

        return rottenTime;
    }
};