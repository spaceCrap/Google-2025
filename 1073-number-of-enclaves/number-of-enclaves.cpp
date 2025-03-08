class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        int totalLand=0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(row==0 || row==m-1 || col==0 || col==n-1)
                {
                    if(grid[row][col]==1 and !visited[row][col])
                    {
                        q.push({row,col});
                        visited[row][col]=1;
                    }
                }
            }
        }
        // row-1, col 
        // row, col+1
        // row+1, col
        // row, col-1

        int deltaRow[]= {-1,0,1,0};
        int deltaCol[]= {0,1,0,-1};

        while(!q.empty())
        {
            int row= q.front().first;
            int col = q.front().second;
            q.pop();

            for(int neighbour =0 ; neighbour<4;neighbour++)
            {
                int nRow= row+deltaRow[neighbour];
                int nCol= col+deltaCol[neighbour];

                if(nRow>=0 and nRow<m and nCol >=0 and nCol <n and grid[nRow][nCol]==1 and !visited[nRow][nCol])
                {
                    visited[nRow][nCol]=1;
                    q.push({nRow,nCol});
                }

            }
        }

        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==1 and !visited[row][col])
                {
                    totalLand++;
                }
            }
        }

        return totalLand;        
    }
};