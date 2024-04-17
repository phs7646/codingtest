def minmove(x,y,r,c) :
    return abs(r-x) + abs(c-y)

def solution(n, m, x, y, r, c, k):
    
    if k < minmove(x,y,r,c) or (k - minmove(x, y, r, c)) % 2 != 0:
        return "impossible"

    cx,cy = y-1,x-1
    r,c = c-1,r-1
    answer = ''
    while(k > 0) :
        print("cx : " + str(cx) + " cy : " + str(cy) + " k : " + str(k))
        if cy+1 < n and minmove(cx,cy+1,r,c) <= k-1: #down
            answer = answer + 'd'
            cy += 1
            k -= 1
        elif cx-1 >= 0 and minmove(cx-1,cy,r,c) <= k-1: #left
            answer = answer + 'l'
            cx -= 1
            k -= 1
        elif cx+1 < m and minmove(cx+1,cy,r,c) <= k-1: #right
            answer = answer + 'r'
            cx += 1
            k -= 1
        elif cy-1 >= 0 and minmove(cx,cy-1,r,c) <= k-1: #up
            answer = answer + 'u'
            cy -= 1
            k -= 1
        else :
            return "must not be here"
    
    
    return answer