#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

#define debug 0
#define maxID 1000000007
#define maxSTUDENT 20007

//data structure
class Node{
public :
	int id;
	int score;
	Node(int x,int y):id(x),score(y) {};
};
bool operator<(const Node& n1,const Node& n2) {
	if(n1.score != n2.score) return n1.score < n2.score;
	else return n1.id < n2.id;
}


//globals
unordered_map<int,int> IdToIdx;
int IdxToId[maxSTUDENT];
int IdxToGrade[maxSTUDENT];
bool IdxToGender[maxSTUDENT];
int IdxToScore[maxSTUDENT];
int num_Idx;
bool alive[maxSTUDENT];
vector<Node> arr[3][2]; //grade * 2 + gender



//helpers
int getIdx(int Id) {
	if(IdToIdx.find(Id) != IdToIdx.end()) return IdToIdx[Id];
	else return IdToIdx[Id] = num_Idx++;
}

void printStatus() {
	for(int grade = 0;grade < 3;grade++) {
			for(int gender = 0;gender < 2;gender++) {
				cout << " - ";
				for(Node n : arr[grade][gender]) cout << "{"<<n.id<<","<<n.score<<"} ";
				cout << endl;
			}
		}
}
//functions
void init() {
	if(debug) cout << "init Called\n";
	IdToIdx.clear();
	//fill(IdxToId,IdxToId+maxSTUDENT,-1);
	num_Idx = 0;
	fill(alive,alive+maxSTUDENT,true);
	for(int g = 0;g < 3;g++) {
		arr[g][0].clear();
		arr[g][1].clear();
	}
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
	if(debug) {
		cout << "Add Called\n"; //printStatus();
	}
	int mIdx = getIdx(mId);
	bool gender = (mGender[0] == 'f');
	//target arr is arr[mGrade-1][gender]
	Node n = Node(mId,mScore);
	arr[mGrade-1][gender].insert(lower_bound(arr[mGrade-1][gender].begin(),arr[mGrade-1][gender].end(),n),n);
	if(debug) {
		cout << "After Insert\n"; printStatus();
	}
	IdxToGrade[mIdx] = mGrade-1;
	IdxToGender[mIdx] = gender;
	IdxToScore[mIdx] = mScore;
	auto it = arr[mGrade-1][gender].end() -1 ;
	return (*it).id; //반드시 한명 이상은 생존함
}

int remove(int mId) {
	if(debug) cout << "Remove Called\n";
	if(IdToIdx.find(mId) == IdToIdx.end()) return 0;
	int mIdx = getIdx(mId);
	if(!alive[mIdx]) return 0;
	//반드시 존재
	int grade = IdxToGrade[mIdx];
	bool gender = IdxToGender[mIdx];
	alive[mIdx] = false;
	Node q = Node(mId,IdxToScore[mIdx]);
	//삭제
	auto it = lower_bound(arr[grade][gender].begin(),arr[grade][gender].end(),q);
	arr[grade][gender].erase(it);
	//반환값 찾기
	if(arr[grade][gender].size() == 0) return 0;
	//가장 점수가 작고, Id도 작은 학생 리턴
	it = arr[grade][gender].begin();
	return (*it).id;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) { //남자 0 여자 1
	if(debug) {
		cout << "Query Called\n";
		printStatus();
	}
	vector<Node> candidates;
	Node query = Node(0,mScore);
	bool genderOk[2] = {false,false};
	for(int gc = 0;gc < mGenderCnt;gc++) {
		if(mGender[gc][0] == 'm') genderOk[0] = true;
		else genderOk[1] = true;
	}
	
	for(int gc = 0;gc < mGradeCnt;gc++) {
		int grade = mGrade[gc]-1;
		for(int gender = 0;gender < 2;gender++) {
			if(!genderOk[gender]) continue;
			//target is arr[grade][gender]
			if(arr[grade][gender].size() == 0) continue;
			auto it = lower_bound(arr[grade][gender].begin(),arr[grade][gender].end(),query);
			if(it != arr[grade][gender].end()) {
				candidates.push_back(*it);
			}
		}
	}
	if(candidates.size() == 0)return 0;
	sort(candidates.begin(),candidates.end());
	if(debug) {
		cout << "Query candidates after sort : ";
		for(Node n : candidates) cout << n.id << " ";
		cout << endl;
	}
	return candidates[0].id;
}