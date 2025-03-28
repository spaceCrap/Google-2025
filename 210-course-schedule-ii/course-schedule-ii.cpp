class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> result;

        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][1];
            int b = prerequisites[i][0];

            adjList[a].push_back(b);
            indegree[b]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (auto& neigbhour : adjList[node]) {
                indegree[neigbhour]--;
                if (indegree[neigbhour] == 0) {
                    q.push(neigbhour);
                }
            }
        }
        if(result.size()== numCourses)
        {
 return result;
        }
        return {};

       
    }
};