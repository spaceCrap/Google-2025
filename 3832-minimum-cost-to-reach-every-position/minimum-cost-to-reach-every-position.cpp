class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int min = cost[0];
        int n = cost.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
           
            if (cost[i] < min) {
                min = cost[i];
            }
             result[i] = min;
        }

        return result;
    }
};