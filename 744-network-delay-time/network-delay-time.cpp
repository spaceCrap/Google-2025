class Solution {
private:
    typedef pair<int, int> pint;

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        vector<int> dist(n + 1, 1e9);
        priority_queue<pint, vector<pint>, greater<pint>> pq;
        int srcNode = k;
        dist[srcNode] = 0;
        // distance, node
        pq.push({dist[srcNode], srcNode});

        for (int i = 0; i < times.size(); i++) {
            int a = times[i][0];
            int b = times[i][1];
            int time = times[i][2];
            // a- > {node, dist}
            adjList[a].push_back({b, time});
        }

        while (!pq.empty()) {
            auto [disNode, node] = pq.top();
            pq.pop();

            for (auto nbr : adjList[node]) {
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if (dist[nbrNode] > disNode + nbrDist) {
                    dist[nbrNode] = disNode + nbrDist;
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }

        int result = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == 1e9) {
                return -1;
            } else
                result = max(result, dist[i]);
        }
        return result;
    }
};