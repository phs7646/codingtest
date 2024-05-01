N,M = map(int, input().split())
states = list(map(int, input().split()))

commands = [list(map(int, input().split())) for _ in range(M)]

for command in commands :
    cmd, a, b = command
    if cmd == 1 :
        states[a-1] = b
    elif cmd == 2 :
        a-=1
        b-=1
        while(a <= b) :
            if states[a] == 0 :
                states[a] = 1
            else :
                states[a] = 0
            a += 1
    elif cmd == 3 :
        a-=1
        b-=1
        while(a <= b) :
            states[a] = 0
            a+=1
    else :
        a-=1
        b-=1
        while(a <= b) :
            states[a] = 1
            a+=1

print(" ".join(map(str,states)))
        
        
        
    