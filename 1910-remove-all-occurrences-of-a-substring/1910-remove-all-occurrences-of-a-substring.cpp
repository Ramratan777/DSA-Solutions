
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();
        stack<char> st;

        for (char c : s) {
            st.push(c);

            if (st.top() == part[m - 1]) {
                stack<char> temp;
                int k = 1;

                while (!st.empty() && k <= m &&
                       st.top() == part[m - k]) {
                    temp.push(st.top());
                    st.pop();
                    k++;
                }

                if (k <= m) {
                    while (!temp.empty()) {
                        st.push(temp.top());
                        temp.pop();
                    }
                }
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
