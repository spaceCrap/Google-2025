class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int water = 1;
        int land = 0;
        int heightOfWater = 0;

        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> heightResult(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        // {{1,1},0} - > cordinates, height
        queue<pair<pair<int, int>, int>> q;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (isWater[row][col] == 1) {
                    q.push({{row, col}, heightOfWater});
                    visited[row][col] = 1;
                }
            }
        }
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int height = q.front().second;
            q.pop();
            heightResult[row][col] = height;

            for (int i = 0; i < 4; i++) {
                int nRow = row + deltaRow[i];
                int nCol = col + deltaCol[i];
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                    isWater[nRow][nCol] == land and !visited[nRow][nCol]) {
                    visited[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, height + 1});
                }
            }
        }
        return heightResult;
    }
};

// isWater =

// [[0,1],
//  [0,0]]

// visited -> initialise 0
// [[0,1],
//  [0,0]]

// queue  : {{1,1},0}

// result/height
// [
//   [0,0]
//   [0,0]
// ]

// [[1,0],
//  [2,1]]

// 0 represent land
// 1 represent water