#include <utility> 

class Twitter {
private:
    unordered_map<int, set<int>> userToFollows;
    vector<pair<int,int>> allTweets;
public:
    
    void postTweet(int userId, int tweetId) {
        allTweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        for(int i = allTweets.size()-1; i >= 0; i--) {
            if(res.size() == 10) break;

            if(userToFollows[userId].count(allTweets[i].first) || userId == allTweets[i].first) {
                res.push_back(allTweets[i].second);
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        userToFollows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userToFollows[followerId].erase(followeeId);
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