class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> frequentmap{};
    for (int i = 0; i < nums.size(); i++) {
      frequentmap[nums[i]]++;
    }

    vector<pair<int, int>> temp;
    for (const auto a : frequentmap) {
      temp.emplace_back(a);
    }

    sort(temp.begin(), temp.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.second > b.second;
    });

    vector<int> result;
    for (int i = 0; i < k; i++) {
      result.emplace_back(temp[i].first);
    }

    return result;
  }
};
