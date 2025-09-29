class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        vector<vector<int>> res;
        vector<int> comb;
        std::sort(candidates.begin(), candidates.end());
        _combinationSum2(res, candidates, comb, 0, target);
        return res;
    }

    void _combinationSum2(vector<vector<int>> &res, vector<int> &candidates, vector<int> &comb, int start, int left)
    {
        if (left == 0)
        {
            res.push_back(comb);
            return;
        }
        else if (left < 0)
        {
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            comb.push_back(candidates[i]);
            _combinationSum2(res, candidates, comb, i + 1, left - candidates[i]);
            comb.pop_back();
        }
    }
};
