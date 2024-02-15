class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = p.length();
        unordered_map<char, int> m, target;
        int l = s.length();
        vector<int> ans;
        int i = 0, j = 0;

        // Initialize the target map with the characters and their counts in string p
        for (char c : p)
        {
            target[c]++;
        }

        while (j < l)
        {
            m[s[j]]++;

            // Check if we have reached a window of size n
            if (j - i + 1 == n)
            {
                // Compare the content of the two maps
                if (m == target)
                {
                    ans.push_back(i);
                }

                m[s[i]]--;

                // If the count becomes 0, remove the entry from the map
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }

                i++;
            }
            j++;
        }

        return ans;
    }
};
