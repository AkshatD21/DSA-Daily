//CODE 1:

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // ek map banao

        unordered_map<int, int> m;

        // if value mili toh true vrna push kro, if koi value nahi mili end tk toh false return kr dena
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
            {
                if (abs(i - m[nums[i]] <= k))
                    return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};





// CODE 2:

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); ++i)
        {
            // If the size of the set exceeds k, remove the leftmost element from the set (sliding window)
            if (i > k)
            {
                window.erase(nums[i - k - 1]);
            }

            // If the current element is already in the set, return true
            if (window.find(nums[i]) != window.end())
            {
                return true;
            }

            // Add the current element to the set
            window.insert(nums[i]);
        }

        // If no such pair is found, return false
        return false;
    }
};