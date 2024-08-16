#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

//members

//unique Id Maps
//userId
unordered_map<int, int> userIdMap;
int realUserId[501]; // index -> id
int _userSize;
//channelId
unordered_map<int, int> channelIdMap;
int  realChannelId[501];
int _channelSize;
//newsId
unordered_map<int, int> newsIdMap;
int realNewsId[30001];
int _newsSize;
typedef struct {
	int mTime;
	int newsIdx;
	int channelIdx;
}work;
struct workCompare {
	bool operator()(work& w1, work& w2) {
		return w1.mTime > w2.mTime;
	}
};
priority_queue<work, vector<work>, workCompare> workQueue;

//global members
int curTime;
vector<int> subscribers[501]; //channelId -> vector<UserId>
bool alive[30001]; //is NewsIdx alive?
int timeOfNews[30001]; //mTime of News
vector<int> newsBox[501]; //userId -> vector<newsId>

//helpers
int getUserIdx(int realId) { //id -> index
	if (userIdMap.find(realId) != userIdMap.end()) return userIdMap[realId];
	int newId = _userSize++;
	userIdMap[realId] = newId;
	realUserId[newId] = realId;
	return newId;
}
int getChannelIdx(int realId) { //id -> index
	if (channelIdMap.find(realId) != channelIdMap.end()) return channelIdMap[realId];
	int newId = _channelSize++;
	channelIdMap[realId] = newId;
	realChannelId[newId] = realId;
	return newId;
}
int getNewsIdx(int realId) { //id -> index
	if (newsIdMap.find(realId) != newsIdMap.end()) return newsIdMap[realId];
	int newId = _newsSize++;
	newsIdMap[realId] = newId;
	realNewsId[newId] = realId;
	return newId;
}

void progress(int targetTime) {
	//if (debug) cout << "Progress called from " << curTime << " to " << targetTime << endl;
	//curTime -> targetTime
	curTime = targetTime;
	while (!workQueue.empty()) {
		work w = workQueue.top();
		//if (debug) cout << "front of workQueue time : " << w.mTime << " and cur time is " << curTime << endl;
		if (w.mTime > curTime) break;
		workQueue.pop();
		for (int userIdx : subscribers[w.channelIdx]) {
			newsBox[userIdx].push_back(w.newsIdx);
		}
	}
}

//functions
void init(int N, int K)
{
	//initialize Id Maps
	userIdMap.clear();
	//fill(realUserId, realUserId + 501, -1);
	_userSize = 0;
	channelIdMap.clear();
	//fill(realChannelId, realChannelId + 501, -1);
	_channelSize = 0;
	newsIdMap.clear();
	//fill(realNewsId, realNewsId + _newsSize, 0);
	//fill(timeOfNews, timeOfNews + _newsSize, 0);
	fill(alive, alive + 30001, true);
	_newsSize = 0;
	//initialize global members
	curTime = 0;
	for (int i = 0; i < 501; i++) subscribers[i].clear();
	for (int i = 0; i < 501; i++) newsBox[i].clear();
	workQueue = priority_queue<work, vector<work>, workCompare>();
}

void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[])
{
	progress(mTime);
	int userIdx = getUserIdx(mUID);
	for (int i = 0; i < mNum; i++) {
		int channelIdx = getChannelIdx(mChannelIDs[i]);
		subscribers[channelIdx].push_back(userIdx);
	}
}

int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID)
{
	progress(mTime);
	work w;
	w.mTime = mTime + mDelay;
	w.newsIdx = getNewsIdx(mNewsID);
	w.channelIdx = getChannelIdx(mChannelID);
	workQueue.push(w);
	timeOfNews[w.newsIdx] = w.mTime;
	return subscribers[w.channelIdx].size();
}

void cancelNews(int mTime, int mNewsID)
{
	progress(mTime);
	alive[getNewsIdx(mNewsID)] = false;
}

struct customCompare {
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
		if (p1.first != p2.first) return p1.first < p2.first;
		else return p1.second < p2.second;
	}
};

int checkUser(int mTime, int mUID, int mRetIDs[])
{
	progress(mTime);

	int userIdx = getUserIdx(mUID);
	priority_queue<pair<int, int>, vector<pair<int, int>>, customCompare> pq;

	for (int newsIdx : newsBox[userIdx]) {
		if (alive[newsIdx]) {
			pq.push({ timeOfNews[newsIdx],realNewsId[newsIdx] });
		}
	}

	newsBox[userIdx].clear();
	int pqSize = pq.size();
	int retNum = 3 > pqSize ? pqSize : 3;
	for (int i = 0; i < retNum; i++) {
		mRetIDs[i] = pq.top().second;
		pq.pop();
	}
	return pqSize;
}