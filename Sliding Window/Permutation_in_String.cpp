class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        // ek vector to store the freq of s1 k characters. the 2nd vector is to store the freq of
        // s2 k char and match if it is equal to previous
        vector<int> freq(26, 0), freqW(26, 0);

        // freq of char pf s1 store krlia
        for (int i = 0; i < s1.length(); i++)
        {
            freq[s1[i] - 'a']++;
        }

        for (int i = 0; i < s1.length(); ++i)
        {
            freqW[s2[i] - 'a']++;
        }

        if (freq == freqW)
            return true;

        // ab upr wala if true nahi hua toh ek ek kark traverse krenge aur equate krenge.
        for (int i = s1.length(); i < s2.length(); i++)
        {
            freqW[s2[i - s1.length()] - 'a']--;
            freqW[s2[i] - 'a']++;

            if (freq == freqW)
                return true;
        }

        return false;
    }
};