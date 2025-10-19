#include <iostream>
#include <vector>

using namespace std;

class Twitter {
public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    tweets[userId].push_front({time, tweetId});
    if (tweets[userId].size() > 10) {
      tweets[userId].pop_back();
    }
  }

  vector<int> getNewsFeed(int userId) {
    for (auto &idx : um[userId]) {
      for (auto &val : tweets[idx]) {
        pq.push(val);
      }
    }

    // push own tweets
    for (auto &val : tweets[userId]) {
      pq.push(val);
    }
    vector<int> res;

    int n = 0;
    while (n < 10) {
      if (pq.empty())
        break;
      res.push_back(pq.top().second);
      pq.pop();

      n++;
    }

    pq = priority_queue<pair<int, int>>();

    return res;
  }

  void follow(int followerId, int followeeId) {
    um[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    um[followerId].erase(followeeId);
  }

  unordered_map<int, set<int>> um;
  priority_queue<pair<int, int>> pq; // time , value
  vector<list<pair<int, int>>> tweets(1001);
  int time = 0;
};

int main() { Solution s{}; }
