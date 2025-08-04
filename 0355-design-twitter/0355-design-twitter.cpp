#include <utility> 

class Twitter {
private:
    unordered_map<int, set<int>> userToFollows;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    int time = 0;
public:
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweetMap[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        
        if(tweetMap.find(userId) != tweetMap.end()) {
            for(int i = 0; i < tweetMap[userId].size(); i++) {
                pq.push(tweetMap[userId][i]);
            }
        }

        for(auto it : userToFollows[userId]) {
            if(tweetMap.find(it) != tweetMap.end()) {
                for(int i = 0; i < tweetMap[it].size(); i++) {
                    pq.push(tweetMap[it][i]);
                }
            }
        }

        while(!pq.empty() && res.size()<10) {
            res.push_back(pq.top().second);
            pq.pop();
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