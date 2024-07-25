class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int size = cost.size();
        int first = 0;
        int second = 0;
        for (int i = 0; i < size - 1; i++)
        {
            int tempt = second;
            second = min(first + cost[i], second + cost[i + 1]);
            first = tempt;
        }
        return second;
    }
};
