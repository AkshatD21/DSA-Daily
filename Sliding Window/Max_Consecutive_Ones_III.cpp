class Solution
{
public:
    int longestOnes(vector<int> &s, int k)
    {
        int n = s.size();
        int zeroCount = 0;
        int maxL = 0;
        vector<int> nums;
        int i = 0;

        for (int j = 0; j < n; j++)
        {
            if (s[j] == 0)
                zeroCount++;

            while (zeroCount > k)
            {
                if (s[i] == 0)
                    zeroCount--;
                i++;
            }

            maxL = max(maxL, j - i + 1);
        }
        return maxL;
    }
};