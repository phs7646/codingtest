#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

#define maxMonarch 10001
#define debug 0

using namespace std;

//members
map<string,int> nameToId; //Monarch name -> Monarch id
map<int,vector<int>> enemies; //Manrach id -> list of enemies root
int ownedBy[25][25]; //terriory -> Monarch id
int numSoldiers[25][25]; //territory -> num Soldiers
int rootAlly[maxMonarch]; //0 : self
int mapSize;
int _size = 1;

//helpers
int getIdFromName(string s) {
    //Monarch String -> Monarch unique id
	if(nameToId.find(s) != nameToId.end()) return nameToId[s];
    nameToId[s] = _size++;
	return _size-1;
}
int findRoot(int id) {
	//cout << "findRoot called " << id << endl;
	//find root of id
	if(rootAlly[id] == 0) return id; //self is root
	return rootAlly[id] = findRoot(rootAlly[id]);
}
void printNumSoldiers() {
	cout << "----Map----\n";
	for(int i = 0;i < mapSize;i++) {
		for(int j = 0;j < mapSize;j++) {
			cout << numSoldiers[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------\n";
}
void printAlly() {
	cout << "Ally status\n";
	for(int i = 1;i < _size;i++) {
		cout << rootAlly[i] << " ";
	}
	cout << endl;
}


//functions
void init(int N, int mSoldier[25][25], char mMonarch[25][25][11])
{
	if(debug) cout << "init called..!\n";
	mapSize = N;
	nameToId.clear();
	enemies.clear();
	fill(rootAlly,rootAlly+maxMonarch,0);
	_size = 1;
	for(int i = 0;i < N;i++) {
		for(int j = 0;j < N;j++) {
			int id = getIdFromName(mMonarch[i][j]);
			ownedBy[i][j] = id;
			rootAlly[id] = 0; //self
			numSoldiers[i][j] = mSoldier[i][j];
		}
	}
}

void destroy()
{
	//exit(0);
}

int ally(char mMonarchA[11], char mMonarchB[11])
{
	if(debug) printNumSoldiers();
	
	int Aid = getIdFromName(mMonarchA);
	int Bid = getIdFromName(mMonarchB);
	
	int rootA = findRoot(Aid);
	int rootB = findRoot(Bid);
	if(debug) {
		cout << "ally called for " << Aid << " " << Bid << endl;
		cout << "rootA : " << rootA <<  " rootB : " << rootB << endl;
		cout << "before ";
		printAlly();
	}
	if(rootA == rootB) return -1; //동일 동맹
	//적대 체크
	if(enemies.find(rootA) != enemies.end()) {
		for(int enemy : enemies[rootA]) {
			if(enemy == rootB) return -2; //적대
		}
	}
	//통합시키기
	if(rootAlly[Aid] == 0 && rootAlly[Bid] == 0) {
		//둘다 root임
		rootAlly[Aid] = Bid;
		//Aid의 적대관계를 Bid가 상속함
		
		for(int enemy : enemies[Aid]) {
			//enemies[enemy].erase(find(enemies[enemy].begin(),enemies[enemy].end(),Aid));
			enemies[Bid].push_back(enemy);
			enemies[enemy].push_back(Bid);
		}
		
	} else if(rootAlly[Aid] == 0) {
		//Aid가 root임
		//Bid는 tree아래임
		rootAlly[Aid] = rootB;
		//Aid의 적대관계를 rootB가 상속함
		
		for(int enemy : enemies[Aid]) {
			//enemies[enemy].erase(find(enemies[enemy].begin(),enemies[enemy].end(),Aid));
			enemies[rootB].push_back(enemy);
			enemies[enemy].push_back(rootB);
		}
		
	} else if(rootAlly[Bid] == 0) {
		//Bid가 root임
		//Aid는 tree아래임
		rootAlly[Bid] = rootA;
		//Bid의 적대관계를 rootA가 상속함
		
		for(int enemy : enemies[Bid]) {
			//enemies[enemy].erase(find(enemies[enemy].begin(),enemies[enemy].end(),Bid));
			enemies[rootA].push_back(enemy);
			enemies[enemy].push_back(rootA);
		}
		
	} else {
		//둘다 트리 아래임
		rootAlly[rootA] = rootB; //A를 B의 산하에 넣음
		//rootA의 적대관계를 rootA가 상속함
		for(int enemy : enemies[rootA]) {
			//enemies[enemy].erase(find(enemies[enemy].begin(),enemies[enemy].end(),rootA));
			enemies[rootB].push_back(enemy);
			enemies[enemy].push_back(rootB);
		}
	}
	if(debug) {
		cout << "Ally success..!!\n";
		cout << "After ";
		printAlly();
	}
	return 1;
}

int attack(char mMonarchA[11], char mMonarchB[11], char mGeneral[11])
{
	if(debug) printNumSoldiers();
	if(debug) cout << "attack called\n";
	//공격자 A, 수비자 B
	int Aid = getIdFromName(mMonarchA);
	int Bid = getIdFromName(mMonarchB);
	int rootA = findRoot(Aid);
	int rootB = findRoot(Bid);
	if(rootA == rootB) {
		if(debug) {
			cout << "No war because same ally\n";
			printAlly();
			cout << "Aid vs Bid : " <<Aid << " vs " << Bid << endl;
			cout << "rootA vs rootB : " << rootA << " vs " << rootB << endl;
		}
		return -1; //동일 동맹
	}

	//moncarchB의 영토 찾기
	int targeti = -1;
	int targetj = -1;
	for(int i = 0;i < mapSize;i++) {
		for(int j = 0;j < mapSize;j++) {
			if(ownedBy[i][j] == Bid) {
				targeti = i;
				targetj = j;
				break;
			}
		}
		if(targeti != -1) break;
	}
	if(debug) cout << "defender territory : " << targeti << "," << targetj << endl;

	//전투가 일어나는지, 공격병사 수, 수비병사 수 체크
	int attacker = 0;
	vector<pair<int,int>> defenders; //추후에 징병하기 위함
	bool isFight = false;
	for(int i = targeti-1; i <= targeti+1;i++) {
		if(i < 0 || i >= mapSize) continue;
		for(int j = targetj-1; j <= targetj+1;j++) {
			if(j < 0 || j >= mapSize) continue;
			if(i==targeti && j == targetj) continue;
			int owner = ownedBy[i][j];
			//owner 너는 누구팀
			int rootOwner = findRoot(owner);
			if(debug) cout << i << "," << j << " owner is " << owner << " root is " << rootOwner << endl;
			if(rootOwner == rootA) {
				//공격자. 여기 온 시점에 전투는 반드시 발생함
				isFight = true;
				int numGo = numSoldiers[i][j]/2;
				numSoldiers[i][j] -= numGo;
				attacker += numGo;
			} else if(rootOwner == rootB) {
				//방어자. 징병 여부는 추후에 결정
				defenders.push_back({i,j});
			}
		}
	}
	if(!isFight) {
		//전투 실패!
		if(debug) cout << "No war!\n";
		return -2;
	}
	//전투 발발. 적대 관계 설립
	enemies[rootA].push_back(rootB);
	enemies[rootB].push_back(rootA);
	//수비 징병
	int defender = numSoldiers[targeti][targetj];
	for(pair<int,int> def : defenders) {
		if(debug) cout << "defender gathered ! " << def.first << "," << def.second << endl;
		int numGo = numSoldiers[def.first][def.second]/2;
		numSoldiers[def.first][def.second] -= numGo;
		defender += numGo;
	}

	if(debug) {
		cout << "War ! attacker : " << attacker << ", deffender : " << defender << endl;
	}

	if(attacker > defender) {
		if(debug) cout << "Attacker win!!\n";
		//공격 성공
		//장수 배정 및 영토 배정
		int newId = getIdFromName(mGeneral);
		rootAlly[newId] = rootA;
		ownedBy[targeti][targetj] = newId;
		numSoldiers[targeti][targetj] = attacker-defender;
		if(debug) cout << "debug here1\n";
		//패배 군주 처형
		if(Bid == rootB) {
			//동맹 리더 rootB 가 바뀌어야함..
			for(int id = 1;id < maxMonarch;id++) {
				if(rootAlly[id] == Bid) {
					//이녀석으로 root를 교체
					rootB = id;
					rootAlly[id] = 0;
					break;
				}
			}
			if(debug) cout << "debug here4\n";
			if(rootB == Bid) {
				//마지막 남은 동맹이었음.. 뭐 안해줘도 됨
				if(debug) cout << "Ally destroyed..\n";
			} else {
				if(debug) cout << "debug here5\n";
				//root 변경 으로 인한 적대관계 계승
				if(enemies.find(Bid) != enemies.end()) {
					for(int enemy : enemies[Bid]) {
						enemies[rootB].push_back(enemy);
						//enemies[enemy].erase(find(enemies[enemy].begin(),enemies[enemy].end(),Bid));
						enemies[enemy].push_back(rootB);
					}
				}
			}
		}
		if(debug) cout << "debug here2\n";
		//B 산하의 군주들 rootB로 업데이트
		for(int id = 1;id < maxMonarch;id++) {
			if(rootAlly[id] == Bid) rootAlly[id] = rootB; //새로운 동맹id
		}
		if(debug) {
			cout << "After ";
			printAlly();
		}
		if(debug) cout << "debug here3\n";
		return 1;
	} else {
		//공격 실패
		if(debug) cout << "Defender Win!!\n";
		numSoldiers[targeti][targetj] = defender - attacker;
		return 0;
	}
	return -3;
}

int recruit(char mMonarch[11], int mNum, int mOption)
{
	if(debug) printNumSoldiers();
	if(debug) cout << "recurit called\n";
	if(mOption == 0) {
		int id = getIdFromName(mMonarch);
		int targeti = -1;
		int targetj = -1;
		for(int i = 0;i < mapSize;i++) {
			for(int j = 0;j < mapSize;j++) {
				if(ownedBy[i][j] == id) {
					targeti = i;
					targetj = j;
					break;
				}
			}
			if(targeti != -1) break;
		}
		numSoldiers[targeti][targetj] += mNum;
		return numSoldiers[targeti][targetj];
	} else {
		int id = getIdFromName(mMonarch);
		int root = findRoot(id);
		int ret = 0;
		for(int i = 0;i < mapSize;i++) {
			for(int j = 0;j < mapSize;j++) {
				int owner = ownedBy[i][j];
				if(findRoot(owner) == root) {
					numSoldiers[i][j] += mNum;
					ret += numSoldiers[i][j];
				} 
			}
		}
		return ret;
	}
	return -1;
}
