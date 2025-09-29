class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, std::greater<pair<double, vector<int>>>> pq; // min heap
        vector<vector<int>> result;
        for (auto &v : points)
        {
            double origin = sqrt(pow(v[0], 2) + pow(v[1], 2));
            pq.push({origin, v});
        }

        while (k > 0)
        {
            auto p = pq.top();
            pq.pop();
            result.push_back(p.second);
            k--;
        }

        return result;
    }
};
