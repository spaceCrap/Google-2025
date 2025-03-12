class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pcnt = 0;
        int ncnt = 0;

        for (auto& num : nums) {
            if (num < 0)
                ncnt++;
            else if (num > 0)
                pcnt++;
        }
        return max(pcnt, ncnt);
    }
};