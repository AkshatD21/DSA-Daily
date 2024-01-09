class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> frequencyMap;
        for (int num : nums)
        {
            frequencyMap[num]++;
        }

        // Create a min-heap to store the k most frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Iterate through the frequency map and maintain the min-heap
        for (auto entry : frequencyMap)
        {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k)
            {
                minHeap.pop(); // Keep the heap size at most k
            }
        }

        // Extract the k most frequent elements from the min-heap
        vector<int> result;
        while (!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        // Reverse the result to get the elements in descending order of frequency
        reverse(result.begin(), result.end());

        return result;
    }
};