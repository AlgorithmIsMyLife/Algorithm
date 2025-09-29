#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> result;
        // sort(candidates.begin(),candidates.end());

        unordered_map<int, int> comb;
        for (auto i : candidates)
        {
            comb[i] = 0;
        }
        _combinationSum(result, candidates, comb, target, 0);
        return result;
    }

    void _combinationSum(vector<vector<int>> &result, vector<int> &candidates, unordered_map<int, int> &comb, int left, int step)
    {
        if (left == 0)
        {
            vector<int> temp;
            for (auto num : comb)
            {
                for (int i = 0; i < num.second; i++)
                {
                    temp.push_back(num.first);
                }
            }
            result.push_back(temp);
            return;
        }
        else if (left < 0 || step >= candidates.size())
        {
            return;
        }

        int freq = 0;

        while (left >= 0)
        {
            comb[candidates[step]] = freq;
            left -= candidates[step] * freq;
            _combinationSum(result, candidates, comb, left, step + 1);
            freq++;
        }
    }
};

int main()
{
    Solution obj;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = obj.combinationSum(candidates, target);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
