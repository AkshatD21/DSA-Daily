class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int maxi = 1;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            int pc = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (s[j] == s[j - 1])
                    pc++;
                if (pc > 1)
                    break;
                maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};