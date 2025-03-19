class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int n = numCourses;
       unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses,0);
         queue<int> q;

       for(int i=0;i<prerequisites.size();i++)
       {
        int a = prerequisites[i][1];
        int b = prerequisites[i][0];
        adjList[a].push_back(b);
        indegree[b]++;


       }

      
      
       for(int i = 0 ; i<n;i++)
       {
        if(indegree[i]==0)
        {
            q.push(i);
        }
       }
       int cnt = 0;

       while(!q.empty())
       {
        int top = q.front();
        q.pop();
        cnt++;

        for(auto neighbour: adjList[top])
        {
            indegree[neighbour]--;
            if( indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }

       }

       if(cnt==numCourses)
       {
        return true;
       }
       return false;
        
    }
};