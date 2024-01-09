/*

APPROACH 1:
 1. ek ek kark elements add krte jao
 2. har bar sort the array while adding
 3. usk baad har baar median nikalo


 APPROACH 2:
 Intiution ye hai ki jitte bhi elements ho , aadhe ko min adho ko max heap mei daalo. Ab jo median hog voh either dono k roots ka sum hoga ya unmei se ek ka root hoga.
 1. make a minheap, and a maxheap
 2. start pushing elements, jab heap empty tb push in maxheap.
 3. jab number maxheap k top se zda toh min heap mei push. Jab chota tab maxheap mei push.
 4. jabb difference between size of min heap and max heap more than 2 tab jiski length zda usk top se element nikal k saamne wale push.
 5. ab even number of elements toh maxheap ka top + minheap ka top ka average
 6. if odd number of elements, tab jis heap ka size bada us heap ka top return ans

 */

class MedianFinder
{
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxh.empty() && minh.empty())
        {
            maxh.push(num);
        }
        else
        {
            if (maxh.top() < num)
            {
                minh.push(num);
            }
            else
            {
                maxh.push(num);
            }
        }

        int n = maxh.size();
        int m = minh.size();

        if (n - m == 2 || n - m == -2)
        {
            if (n > m)
            {
                int element = maxh.top();
                maxh.pop();
                minh.push(element);
            }
            else
            {
                int element = minh.top();
                minh.pop();
                maxh.push(element);
            }
        }
    }

    double findMedian()
    {
        int n = maxh.size();
        int m = minh.size();

        if ((n + m) % 2 == 0)
        {
            return ((double)maxh.top() + (double)minh.top()) / 2.0;
        }

        if (n > m)
            return maxh.top();

        return minh.top();
    }
};

