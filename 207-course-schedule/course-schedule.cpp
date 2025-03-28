class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses,0);
        queue<int> q;
        

        for(auto preq : prerequisites)
        {
            int a = preq[1];
            int b= preq[0];
            adjList[a].push_back(b);
            indegree[b]++;
        }

        for(int i =0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        int topoCnt=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topoCnt++;

            for(auto& neighbour:adjList[node] )
            {
                indegree[neighbour]--;
                if( indegree[neighbour]==0)
                {
                    q.push(neighbour);
                }
            }
        }

        if(topoCnt == numCourses)
        {
            return true;
        }
        else return false;
        
    }
};