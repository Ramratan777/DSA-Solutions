class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<bool>dp(target+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int s=target;s>=num;s--){
                bool take=dp[s-num];
                bool NotTake=dp[s];
                dp[s]=take||NotTake;
            }
        }
        return dp[target];
    }
};