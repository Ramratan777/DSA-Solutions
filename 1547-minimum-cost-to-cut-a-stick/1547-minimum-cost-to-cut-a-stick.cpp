class Solution {
public:
    int cut(int l,int r,vector<vector<int>>&dp,vector<int>&cuts){
        if(r-l<=1){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int minicost=INT_MAX;
        for(int i=l+1;i<r;i++){
            int cost=cuts[r]-cuts[l]+cut(l,i,dp,cuts)+cut(i,r,dp,cuts);
            minicost=min(minicost,cost);
        }
        return dp[l][r]=minicost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int k=cuts.size();
        vector<vector<int>>dp(k,vector<int>(k,-1));
        return cut(0,k-1,dp,cuts);
    }
};