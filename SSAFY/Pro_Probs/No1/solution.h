// functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// 함수 선언
extern void init(int N, int mSoldier[25][25], char mGeneral[25][25][11]);
extern void destroy();
extern int ally(char mMonarchA[11], char mMonarchB[11]);
extern int attack(char mMonarchA[11], char mMonarchB[11], char mGeneral[11]);
extern int recruit(char mMonarch[11], int mNum, int mOption);

#endif // FUNCTIONS_H
