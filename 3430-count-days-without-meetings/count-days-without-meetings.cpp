class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int last = 0;
        int count = 0;
 
        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            if (start > last + 1) {
               count += (start - last - 1);
                
            }  
              last = max(last, end); 
        }
        if (last < days) {
            count += (days - last);
        }
        return count;
    }
};