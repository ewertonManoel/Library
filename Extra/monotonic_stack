vector<int> next_smaller(vector<int>& v) {
    int n = v.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && v[st.top()] > v[i]) {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    return ans;
}