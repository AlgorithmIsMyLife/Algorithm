class Twitter
{
public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        int num = 10;
        unordered_set<int> temp = followMap[userId];
        for (int i = tweets.size() - 1; i >= 0; i--)
        {
            if (tweets[i].first == userId || temp.find(tweets[i].first) != temp.end())
            {
                res.push_back(tweets[i].second);
                num--;
            }
            if (num == 0)
            {
                break;
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId)
    {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followMap[followerId].erase(followeeId);
    }

private:
    unordered_map<int, unordered_set<int>> followMap;
    vector<pair<int, int>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
