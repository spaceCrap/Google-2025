class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> result;

        vector<vector<int>> adjList(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][1];
            int b = prerequisites[i][0];
            adjList[a].push_back(b);
            indegree[b]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            result.push_back(top);

            for (auto neighbour : adjList[top]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        if (result.size() == n) {
            return result;
        }
        return {};
    }
};