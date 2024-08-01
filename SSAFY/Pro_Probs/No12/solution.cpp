#include<cstdlib>

using namespace std;
extern bool checkCards(int mIndexA, int mIndexB, int mDiff);
int maxN;
int arr[100000];
int Answer[] = { 4,3,2,4,2,1,1,3 };


void mySwap(int idx1, int idx2) {
	int t = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = t;
}
void mySort(int start, int end) {
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
	int leftIdx = start + 1;
	int rightIdx = end;
	int mid = -1;
	while (true) {
		//pick leftIdx that result is false
		while (leftIdx <= end && checkCards(arr[start], arr[leftIdx], diff)) leftIdx++;
		if (leftIdx == end + 1) {
			//everything is true..
			mid = end;
			break;
		}
		//pick rightIdx that result is true
		while (rightIdx >= start && !checkCards(arr[start], arr[rightIdx], diff)) rightIdx--;
		if (rightIdx == start - 1) {
			//everything is false.
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
	mySort(start, mid);
	mySort(mid + 1, end);
}

void playGame(int N)
{
	//initialize
	int total = N * 2;
	for (int i = 0; i < total; i++) arr[i] = i;
	maxN = N;
	//logic
	mySort(0, total - 1);
}