//#include<iostream>
#include<deque>
#include<cstring>

//#define debug 0
#define SIZE 301

using namespace std;
deque<char> dq[SIZE];
int aCount[SIZE][26];
int maxRow;
int maxCol;
int curRow;
int curCol;
int len;

/*
void printStatus() {
	cout << "Printing Status ..\n";
	for (int row = 0; row < len / maxCol + 1; row++) {
		for (char c : dq[row]) cout << c << " ";
		cout << endl;
	}
}
*/

void init(int H, int W, char mStr[])
{
	//initialize
	for (int i = 0; i < SIZE; i++) {
		dq[i].clear();
	}
	memset(aCount, 0, sizeof(aCount));
	curRow = 0; curCol = 0;
	len = 0;
	
	//get input
	maxRow = H; maxCol = W;
	while (true) {
		char c = mStr[len];
		if (c == '\0') break;
		int row = len / maxCol;
		dq[row].push_back(c);
		aCount[row][c - 'a']++;
		len++;
	}

	/*
	if (debug) {
		cout << "After init ";
		printStatus();
	}
	*/
	
}

void insert(char mChar)
{
	dq[curRow].insert(dq[curRow].begin() + curCol, mChar);
	aCount[curRow][mChar - 'a']++;
	int row = curRow;
	while (row < maxRow && dq[row].size() > maxCol) {
		//pop current
		char c = dq[row].back(); 
		dq[row].pop_back();
		aCount[row][c - 'a']--;
		//push to next
		row++;
		dq[row].push_front(c);
		aCount[row][c - 'a']++;
	}
	len++;
	curCol++;
	if (curCol == maxCol) {
		curRow++;
		curCol = 0;
	}
	/*
	if (debug) {
		cout << "After insert ";
		printStatus();
	}
	*/
}

char moveCursor(int mRow, int mCol)
{
	mRow--;
	mCol--;
	char ret;
	if (mRow * maxCol + mCol >= len) {
		curRow = len / maxCol;
		curCol = len % maxCol;
		return '$';
	}
	else {
		curRow = mRow;
		curCol = mCol;
		return dq[curRow][curCol];
	}
}

int countCharacter(char mChar)
{
	int ret = 0;
	//count from deque for current row
	auto it = dq[curRow].begin() + curCol;
	while (it != dq[curRow].end()) {
		if (*it == mChar) ret++;
		it++;
	}
	//count from aCount for next row
	int row = curRow + 1;
	for (; row < len / maxCol + 1; row++) {
		ret += aCount[row][mChar - 'a'];
	}
	return ret;
}
