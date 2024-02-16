/* Approach : Sliding Window
1. Calculate array sum
2. if target == array sum -> return ans
3. if target > array sum -> some full array + 1 partial subarray
 3.1 Find partial subarray using sliding window
4. If partial subarray is found -> return ans as required full arrays + partial subarray size
otherwise return -1.
Time : O(n)
Space : O(1)
*/

class Solution
{
public:
    int minSizeSubarray(vector<int> &nums, int target)
    {
        int n = nums.size();
        int count = 0;
        // calculate array sum
        long long arrSum = 0;
        for (int i = 0; i < n; i++)
            arrSum += nums[i];
        // if target is multiple of arrSum
        if (target % arrSum == 0)
            return (target / arrSum) * n;

        // if target > arrSum, we need some whole arrays in ans and a partial subarray
        if (target > arrSum)
        {
            count = (target / arrSum) * n;
            target %= arrSum;
        }

        // Use sliding window to find subarray with target sum in circular array
        int ans = 1e9;
        int l = 0;
        int r = 0;
        long long currSum = 0;
        while (r < 2 * n)
        {
            currSum += nums[r % n]; // include right element
            // shrink left boundary
            while (l <= r && currSum > target)
            {
                currSum -= nums[l % n];
                l++;
            }
            // update ans
            if (currSum == target)
                ans = min(ans, r - l + 1);
            // expand right side
            r++;
        }
        return ans == 1e9 ? -1 : count + ans;
    }
};