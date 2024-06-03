N, M = map(int,input().split())
board = [input() for _ in range(N)]


answer = 64
for i in range(N-7) :
    for j in range(M-7):
        num1 = 0
        num2 = 0
        for y in range(8):
            for x in range(8):
                if (x+y)%2 == 0 :
                    if board[i+y][j+x] == 'B' :
                        num1+=1
                    else :
                        num2+=1
                else :
                    if board[i+y][j+x] == 'B' :
                        num2+=1
                    else :
                        num1+=1
        answer = min(answer,min(num1,num2))
print(answer)