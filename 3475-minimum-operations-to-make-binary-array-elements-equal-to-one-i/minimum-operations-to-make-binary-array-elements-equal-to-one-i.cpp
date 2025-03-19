class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        int i=0;
       
        for( i=0;i<=n-3;i++)
        {
            if(nums[i]==0)
            {
                nums[i]=!nums[i];
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
                count++;
            }
        }
        if(nums[i] && nums[i+1])
        {
            return count;
        }
        return -1;
    }
};

