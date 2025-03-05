class Solution {
private:
    int bfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int r,
            int c, int m, int n) {
        queue<pair<int, int>> q;
        q.push({r, c});

        int area = 1;
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};
        visited[r][c] = 1;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nRow = row + deltaRow[i];
                int nCol = col + deltaCol[i];

                if (nRow >= 0 and nRow < m and nCol >= 0 and nCol < n and
                    visited[nRow][nCol] != 1 and graph[nRow][nCol] == 1) {
                    visited[nRow][nCol] = 1;
                    area++;
                    q.push({nRow, nCol});
                }
            }
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& graph) {
        int m = graph.size();
        int n = graph[0].size();
        int maxArea = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (graph[row][col] == 1 and visited[row][col] != 1) {
                    int area = bfs(graph, visited, row, col, m, n);
                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }
};