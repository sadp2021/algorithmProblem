#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TweetCounts {
 private:
  unordered_map<string, map<int, int>> m;

 public:
  TweetCounts() {}

  void recordTweet(string tweetName, int time) { m[tweetName][time]++; }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
                                         int startTime, int endTime) {
    int delta = 0;
    if (freq == "minute") {
      delta = 60;
    } else if (freq == "hour") {
      delta = 60 * 60;
    } else {
      delta = 60 * 60 * 24;
    }

    vector<int> ans;
    int t = startTime;
    while (t <= endTime) {
      auto bg = m[tweetName].lower_bound(t);
      auto ed = m[tweetName].upper_bound(min(t + delta - 1, endTime));
      int cnt = 0;
      for (auto it = bg; it != ed; it++) {
        cnt += it->second;
      }
      ans.push_back(cnt);
      t += delta;
    }
    return ans;
  }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 =
 * obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */