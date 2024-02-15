class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int ones = 0, x = 0, oiw = 0, i = 0, n = nums.size();

        ones = count(begin(nums), end(nums), 1);
        vector<int> nums2(n * 2);

        for (i = 0; i < n * 2; i++)
        {
            nums2[i] = nums[i % n];
        }

        for (i = 0; i < n * 2; i++)
        {
            if (nums2[i] == 1)
                x++;

            if (i >= ones && nums2[i - ones] == 1)
                x--;

            oiw = max(x, oiw);
        }

        return ones - oiw;
    }
};