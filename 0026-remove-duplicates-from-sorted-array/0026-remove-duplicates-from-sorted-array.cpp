class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=nums[i];
            int j=i+1;
            while(j<n&&nums[j]==a){
                nums[j]=101;
                j++;
            }
            i=j-1;
        }
        int k=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=101){
                k++;
            }
        }
        return k;
    }
};