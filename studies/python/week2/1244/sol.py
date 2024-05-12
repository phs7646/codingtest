
N = int(input())
switch = list(map(int,input().split()))
n = int(input())
for _ in range(n) :
    gender, s = map(int,input().split())
    if gender == 1 :
        for i in range(s-1,N,s):
            switch[i] ^= 1
    else :
        left = s-1
        right = s-1
        while left > 0 and right < N - 1 and switch[left - 1] == switch[right + 1]:
            left -= 1
            right += 1
        # Toggle all switches from l to r.
        for i in range(left, right + 1):
            switch[i] ^= 1

for i in range(0,N,20):
    print(" ".join(list(map(str,switch[i:i+20]))))