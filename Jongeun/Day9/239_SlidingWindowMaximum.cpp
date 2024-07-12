class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        int l = 0;
        int r = 0;
        deque<int> dq;
        vector<int> maxWindow;

        while (r < nums.size())
        {
            while (!dq.empty() && nums[dq.back()] <= nums[r])
            {
                dq.pop_back();
            }

            dq.emplace_back(r);

            if (l > dq.front())
            {
                dq.pop_front();
            }

            if (r + 1 >= k)
            {
                maxWindow.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }

        return maxWindow;
    }
};
