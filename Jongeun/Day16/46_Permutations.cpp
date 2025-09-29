class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> ans;
        unordered_map<int, int> m;
        for (auto i : nums)
        {
            m[i] = 1;
        }
        _permute(res, ans, m);
        return res;
    }

    void _permute(vector<vector<int>> &res, vector<int> &ans, unordered_map<int, int> &m)
    {
        if (ans.size() == m.size())
        {
            res.push_back(ans);
            return;
        }

        for (auto &it : m)
        {
            if (it.second == 1)
            {
                it.second--;
                ans.push_back(it.first);
                _permute(res, ans, m);
                ans.pop_back();
                it.second++;
            }
        }
    }
};
