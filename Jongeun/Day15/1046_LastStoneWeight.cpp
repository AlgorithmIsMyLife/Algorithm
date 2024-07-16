#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> mpq;
        for (auto i : stones)
        {
            mpq.push(i);
        }

        while (mpq.size() > 1)
        {
            int m1 = mpq.top();
            mpq.pop();
            int m2 = mpq.top();
            mpq.pop();

            if (abs(m1 - m2) != 0)
            {
                int m3 = abs(m1 - m2);
                mpq.push(m2);
            }
        }

        if (mpq.empty())
        {
            return 0;
        }
        else
        {
            return mpq.top();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << sol.lastStoneWeight(stones) << endl;
    return 0;
}
