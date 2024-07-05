class TimeMap
{
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        timeMap[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {

        auto it = timeMap.find(key);
        if (it != timeMap.end())
        { // find the key
            const vector<pair<int, string>> &timeVec = it->second;
            int l = 0;
            int r = timeVec.size() - 1;
            int mid;

            // if length == 1
            if (r == 0)
            {
                if (timeVec[0].first <= timestamp)
                {
                    return timeVec[mid].second;
                }
            }

            // until two things left
            while (r - l > 1)
            {
                mid = (l + r) / 2;
                if (timeVec[mid].first == timestamp)
                {
                    return timeVec[mid].second;
                }
                if (timeVec[mid].first < timestamp)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }

            // two or one thing left
            if (timestamp < timeVec[l].first)
            {
                return "";
            }
            else if (timestamp >= timeVec[r].first)
            {
                return timeVec[r].second;
            }
            else
            {
                return timeVec[l].second;
            }
        }
        else
        {
            // not have key
            return "";
        }
    }

private:
    unordered_map<string, vector<pair<int, string>>> timeMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
