class Solution {
public:
    vector<int> prev(vector<int >arr){
        int n=arr.size();
        vector<int>prevs(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                prevs[i]=-1;
            }else{
                prevs[i]=st.top();
            }
            st.push(i);
        }
        return prevs;
    }
    vector<int> next(vector<int >arr){
        int n=arr.size();
        vector<int>nexts(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nexts[i]=n;
            }else{
                nexts[i]=st.top();
            }
            st.push(i);
        }
        return nexts;
    }
    int getMaxArea(vector<int> &arr) {
        vector<int>prevsmall=prev(arr);
        vector<int>nextsmall=next(arr);
        int maxi=0;
        for (int i = 0; i < arr.size(); ++i) {
            int width = nextsmall[i] - prevsmall[i] - 1; 
            int area = arr[i] * width;          
            maxi = max(maxi, area);        
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>heights(n,0);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }else{
                    heights[j]=0;
                }
            }
            ans=max(ans,getMaxArea(heights));
        }
        return ans;
    }
};