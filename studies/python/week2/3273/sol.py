n = int(input())
arr = list(map(int,input().split()))
X = int(input())
answer = 0

arr = sorted(arr)
left = 0
right = n-1
while left < right :
    if(arr[left] + arr[right] == X) :
        answer+=1
        left+=1
        right-=1
    elif(arr[left] + arr[right] > X) :
        right-=1
    else :
        left+=1
print(answer)
    