A,B,V = map(int,input().split())
answer = (V-A) / (A-B)
if answer - int(answer) == 0 :
    print(int(answer)+1)
else :
    print(int(answer)+2)