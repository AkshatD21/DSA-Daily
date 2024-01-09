vector<int> Solution::solve(vector<int> &a, vector<int> &b, int c)
{
    priority_queue<pair<int, pair<int, int>>> pq; // {sum, (i,j)}
    set<pair<int, int>> st;                       // {i,j}
    vector<int> ans;

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    pq.push({a[0] + b[0], {0, 0}});
    st.insert({0, 0});

    for (int i = 0; i < c; i++)
    {
        auto curPair = pq.top();
        pq.pop();
        int curSum = curPair.first;
        int idx1 = curPair.second.first;
        int idx2 = curPair.second.second;

        ans.push_back(curSum);

        if (idx1 + 1 < a.size() && st.find({idx1 + 1, idx2}) == st.end())
        {
            pq.push({a[idx1 + 1] + b[idx2], {idx1 + 1, idx2}});
            st.insert({idx1 + 1, idx2});
        }

        if (idx2 + 1 < a.size() && st.find({idx1, idx2 + 1}) == st.end())
        {
            pq.push({a[idx1] + b[idx2 + 1], {idx1, idx2 + 1}});
            st.insert({idx1, idx2 + 1});
        }
    }
    return ans;
}
