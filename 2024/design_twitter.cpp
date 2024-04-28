#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Twitter {
 public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    tweet_ranker.push(make_pair(++t, tweetId));
    tweet_mapper[tweetId] = userId;
  }

  vector<int> getNewsFeed(int userId) {
    auto copy = tweet_ranker;
    vector<int> feed;
    while (feed.size() < 10 and not copy.empty()) {
      auto i = copy.top();
      copy.pop();
      int author = tweet_mapper[i.second];
      if (author == userId or follower_list[userId].contains(author))
        feed.push_back(i.second);
    }
    return feed;
  }

  void follow(int followerId, int followeeId) {
    follower_list[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    follower_list[followerId].erase(followeeId);
  }

  int t = 0;
  typedef pair<int, int> pint;
  priority_queue<pint, vector<pint>, less<pint>> tweet_ranker;
  map<int, int> tweet_mapper;
  map<int, set<int>> follower_list;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
