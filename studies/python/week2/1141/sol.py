n = int(input())
words = []
for _ in range(n) :
    words.append(input().strip())
words = sorted(words)
answer = n
for i in range(n-1) :
    flag = True
    for j in range(len(words[i])) :
        if words[i][j] != words[i+1][j] :
            flag = False
            break
    if flag :
        answer -= 1

print(answer)