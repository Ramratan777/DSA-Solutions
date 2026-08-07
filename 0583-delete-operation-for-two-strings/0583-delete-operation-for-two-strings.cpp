class Solution {
public:
    int longest(string s1,string s2){
        int n=s1.size();
        int m=s2.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return ans;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int k=longest(word1,word2);
        return m+n-2*k;
    }
};