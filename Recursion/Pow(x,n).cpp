// APPROACH 1:
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0)
            nn = -1 * nn;

        while (nn)
        {
            if (nn % 2 == 0)
            {
                x = x * x;
                nn = nn / 2;
            }
            else
            {
                ans = ans * x;
                nn = nn - 1;
            }
        }
        if (n < 0)
            ans = (double)(1.0) / (double)(ans);

        return ans;
    }
};

// APPROACH 2:
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == INT_MAX)
        {
            if (x == 1)
                return 1;
            else if (x == -1)
                return -1;
            else
                return 0;
        }
        else if (n == INT_MIN)
        {
            if (x == 1 || x == -1)
                return 1;
            else
                return 0;
        }
        if (n == 0)
            return 1;
        if (n < 0)
        {
            double ans = myPow(x, n + 1) / x;
            return ans;
        }
        return myPow(x, n - 1) * x;
    }
};