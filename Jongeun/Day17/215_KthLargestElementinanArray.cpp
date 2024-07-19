class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, std::vector<int>, std::less<int>>
            mq(nums.begin(), nums.end());

        while (k > 1)
        {
            k--;
            mq.pop();
        }

        return mq.top();
    }
};
