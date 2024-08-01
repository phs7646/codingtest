#include<iostream>
#include<cstdlib>
#define debug 0
using namespace std;
extern bool checkCards(int mIndexA, int mIndexB, int mDiff);
int maxN;
int arr[100000];
int Answer[] = { 4,3,2,4,2,1,1,3 };

void myPrint() {
	for (int i = 0; i < maxN * 2; i++) {
		cout << Answer[arr[i]] << " ";
	}
	cout << endl;
}
void mySwap(int idx1, int idx2) {
	if (debug) cout << "mySwap called for " << idx1 << " " << idx2 << endl;
	int t = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = t;
	if (debug) {
		cout << "After mySwap called.." << endl;
		myPrint();
	}
}
void mySort(int start, int end) {
	if (debug) cout << "mySort call for " << start << " , " << end << endl;
	if (start >= end) return;
	if (start + 1 == end) {
		//Done! send result
		checkCards(arr[start], arr[end], 0);
		return;
	}
	int numCard = end - start + 1; //2N
	int numPair = numCard / 2; //N
	int diff = (numPair - 1) / 2; //if even, -1
	//pivot select
	int pivot = start + rand() % numCard;
	//pivit <-> start swap
	if (pivot != start) mySwap(pivot, start);
	if (debug) {
		cout << "mySort run with before status" << endl;
		myPrint();
		cout << "diff is " << diff << endl;
	}
	int leftIdx = start + 1;
	int rightIdx = end;
	int mid = -1;
	while (true) {
		//pick leftIdx that result is false
		while (leftIdx <= end && checkCards(arr[start], arr[leftIdx], diff)) leftIdx++;
		if (leftIdx == end + 1) {
			//everything is true..
			if (debug) cout << "everything is true\n";
			mid = end;
			break;
		}
		//pick rightIdx that result is true
		while (rightIdx >= start && !checkCards(arr[start], arr[rightIdx], diff)) rightIdx--;
		if (rightIdx == start - 1) {
			//everything is false.
			if (debug) cout << "everything is false\n";
			mid = start;
			break;
		}
		//check left and right
		if (leftIdx > rightIdx) {
			mid = rightIdx;
			break;
		}
		//swap
		mySwap(leftIdx, rightIdx);
		leftIdx++;
		rightIdx--;
		//check again
		if (leftIdx > rightIdx) {
			//sort Done!!
			mid = rightIdx;
			break;
		}
	}
	if (debug) {
		cout << "My sort end with mid : " << mid << endl;
		myPrint();
	}
	mySort(start, mid);
	mySort(mid + 1, end);
}

void playGame(int N)
{
	//initialize
	int total = N * 2;
	for (int i = 0; i < total; i++) arr[i] = i;
	maxN = N;
	if (debug) {
		cout << "initial status : ";
		myPrint();
	}
	//logic
	mySort(0, total-1);
}