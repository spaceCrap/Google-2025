class Solution {
// private: 
// void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int& queryVal, int& points, int m, int n, int row, int col ){
//     visited[row][col] =1;
//     if(grid[row][col]<queryVal)
//     {
//         points++;
//     }
//     else return;

//     int deltaRow[] = {-1,0,1,0};
//     int deltaCol[] = {0,1,0,-1};

//     for(int neighbour =0;neighbour<4;neighbour++)
//     {
//         int nRow = row + deltaRow[neighbour];
//         int nCol = col + deltaCol[neighbour];

//         if(nRow>=0 and nRow<m and nCol>=0 and nCol<n and !visited[nRow][nCol])
//         {
//            dfs(grid,visited, queryVal, points, m, n,nRow,nCol);

//         }
//     }


// }



public:
    // vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     int k = queries.size();
    //     vector<int> result;
    
    //     for(auto query: queries)
    //     {
    //         int points =0;

    //         vector<vector<int>> visited(m, vector<int> (n,0));
    //          dfs(grid,  visited,query, points, m, n,0,0);
    //         result.push_back(points);
    //     }

    //     return result;

        
    // }

    //  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    //     int m = grid.size(), n = grid[0].size();
    //     int k = queries.size();
    //     vector<int> result(k, 0);
        
        
    //     vector<pair<int, int>> sorted_queries;
    //     for (int i = 0; i < k; i++)
    //         sorted_queries.push_back({queries[i], i});
    //     sort(sorted_queries.begin(), sorted_queries.end());

       
    //     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

      
    //     vector<vector<int>> visited(m, vector<int>(n, 0));
    //     pq.push({grid[0][0], {0, 0}});
    //     visited[0][0] = 1;

       
    //     int dr[] = {-1, 0, 1, 0};
    //     int dc[] = {0, 1, 0, -1};

    //     int points = 0, maxGridValue = 0;
    //     int queryIndex = 0;

    //     while (!pq.empty() && queryIndex < k) {
    //         int queryVal = sorted_queries[queryIndex].first;

           
    //         while (!pq.empty() && pq.top().first < queryVal) {
    //             auto [val, pos] = pq.top();
    //             pq.pop();
    //             int r = pos.first, c = pos.second;

               
    //             points++;
    //             maxGridValue = max(maxGridValue, val);

              
    //             for (int i = 0; i < 4; i++) {
    //                 int nr = r + dr[i], nc = c + dc[i];
    //                 if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
    //                     pq.push({grid[nr][nc], {nr, nc}});
    //                     visited[nr][nc] = 1;
    //                 }
    //             }
    //         }

            
    //         result[sorted_queries[queryIndex].second] = points;
    //         queryIndex++;
    //     }

    //     return result;
    // }

        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> ans(queries.size());
        int m=grid.size(),n=grid[0].size();
        vector<pair<int,int>> query;
        for(int i=0;i<queries.size();i++){
            query.push_back({queries[i],i});
        }
        sort(query.begin(),query.end());
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        int index=0;
        int count=0;
        int row[]={1,-1,0,0};
        int col[]={0,0,1,-1};
        while(index<query.size() && !pq.empty() ){
            int val=pq.top().first;
            if(val>=query[index].first){
                ans[query[index].second]=count;
                index++;
                continue;
            }
            int rowIndex=pq.top().second.first;
            int colIndex=pq.top().second.second;
            count++;
            pq.pop();
            for(int i=0;i<4;i++){
                int nRowIndex=rowIndex+row[i];
                int nColIndex=colIndex+col[i];
                if(nRowIndex>=0 && nRowIndex<m && nColIndex>=0 && nColIndex<n && !vis[nRowIndex][nColIndex]){
                    pq.push({grid[nRowIndex][nColIndex],{nRowIndex,nColIndex}});
                    vis[nRowIndex][nColIndex]=true;
                }
            }
        }
        while(index<query.size()){
            ans[query[index].second]=count;
            index++;
        }
        return ans;
    }
};