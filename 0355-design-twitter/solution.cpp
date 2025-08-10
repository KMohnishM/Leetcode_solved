#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    struct Tweet {
        int time;
        int id;
        Tweet(int t, int i) : time(t), id(i) {}
    };

    // user -> set of followees
    unordered_map<int, unordered_set<int>> following;
    // user -> list of tweets
    unordered_map<int, vector<Tweet>> tweets;
    int timestamp;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(timestamp++, tweetId));
    }

    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pair<int,int>> pq; // {time, tweetId}
        
        
        if (tweets.count(userId)) {
            for (auto &tw : tweets[userId]) {
                pq.push({tw.time, tw.id});
            }
        }
        
        
        if (following.count(userId)) {
            for (int followee : following[userId]) {
                if (tweets.count(followee)) {
                    for (auto &tw : tweets[followee]) {
                        pq.push({tw.time, tw.id});
                    }
                }
            }
        }
        
        vector<int> feed;
        while (!pq.empty() && feed.size() < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

