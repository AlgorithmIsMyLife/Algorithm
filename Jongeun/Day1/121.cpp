class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int left = 0;
        int right = 1;
        int sum = 0;
        while (right < prices.size())
        {
            int tempt = prices[right] - prices[left];
            if (prices[right] < prices[left])
            {
                left = right;
                right = left + 1;
            }
            else
            {
                sum = max(sum, tempt);
                right++;
            }
        }
        return sum;
        }
};
