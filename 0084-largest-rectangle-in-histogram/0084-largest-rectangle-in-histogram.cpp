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
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prevsmall=prev(heights);
        vector<int>nextsmall=next(heights);
        int maxi=0;
        for (int i = 0; i < heights.size(); ++i) {
            int width = nextsmall[i] - prevsmall[i] - 1; 
            int area = heights[i] * width;          
            maxi = max(maxi, area);        
        }
        return maxi;
    }
};