// APPROACH 1:
class Solution
{
public:
    int solve(int n, int k)
    {
        if (n == 1)
        {
            return 0;
        }
        return (solve(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k)
    {
        int ans = solve(n, k) + 1;
        return ans;
    }
};

// APPRAOCH 2:
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        k = k - 1;
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        int idx = 0;
        int ans = -1;
        solve(v, k, ans, idx);
        return ans;
    }

    void solve(vector<int> v, int k, int &ans, int idx)
    {
        if (v.size() == 1)
        {
            ans = v[0];
            return;
        }

        idx = (idx + k) % v.size();
        v.erase(v.begin() + idx);

        solve(v, k, ans, idx);
    }
};