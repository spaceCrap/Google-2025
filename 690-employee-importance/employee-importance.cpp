/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

// 1 -> emp(1,5,[2,3])
// 3-> emp(3,3.[])

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> emap;
        // unordered_map<int, int> visited;

        for (auto& emp : employees) {
            emap[emp->id] = emp;
        }

        int total = 0;
        queue<int> q;
        q.push(id);
        // visited[id] = 1;

        while (!q.empty()) {
            int node = q.front();
            total = total + emap[node]->importance;
            q.pop();

            for (auto& neighbour : emap[node]->subordinates) {
                // if (!visited[neighbour]) {
                //     visited[neighbour]=1;
                    q.push(neighbour);
                // }
            }
        }

        return total;
    }
};