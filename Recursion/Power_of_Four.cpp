// Approach 1:

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 0)
            return false;
        while (n % 4 == 0)
        {
            n = n / 4;
        }
        return n == 1;
    }
};

/* Approach 2:
 - we have to find out if 4^x == n, toh x nikal lo
 - x = logn / log4
 - now once we have x, we can check if 4^x == n
 - if hua toh true, vrna false.
 */
