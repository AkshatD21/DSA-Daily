// agar saare characters different hai toh maximum length can be K+1(K+jo pehla charac ho substr ka).

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.length();
        vector<int> count(26, 0); // to store the count of all characters
        int maxC = 0;
        int maxL = 0;
        int start = 0;

        for (int end = 0; end < n; end++)
        {
            count[s[end] - 'A']++;
            maxC = max(maxC, count[s[end] - 'A']);

            while (end - start + 1 - maxC > k)
            {
                count[s[start] - 'A']--;
                start++;
            }
            maxL = max(maxL, end - start + 1);
        }
        return maxL;
    }
};