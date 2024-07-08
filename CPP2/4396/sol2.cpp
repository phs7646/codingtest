/*
 
숫자의 의미: 인접한 8개 칸에 지뢰가 몇 개 있는지 카운트*
*/
#include <iostream>

using namespace std;

char board[10][10]; //선택했던 위치
char bomb[10][10]; //지뢰 위치
char answer[10][10];

int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={-1,-1,0,1,1,1,0,-1};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bool isOpened=false; //지뢰 열림 여부
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>bomb[i][j];
        }
    }



    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];

            if(board[i][j]=='x' && bomb[i][j]=='*'){
                //폭탄 열림
                isOpened=true;
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cnt=0;

            if(bomb[i][j]=='.' && board[i][j]=='x'){
                for(int k=0;k<8;k++){
                    int newX = j + dx[k];
                    int newY = i + dy[k];

                    if(newX<0 ||newY<0 || newX>n ||newY>n) continue;
                    if(bomb[newY][newX]=='*') cnt++;
                }
                answer[i][j]= char(cnt+int('0'));
            }
            else answer[i][j]='.';
        }
    }


    if(isOpened){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(bomb[i][j]=='*') answer[i][j]='*';
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< answer[i][j];
        }
        cout<<"\n";
    }

}