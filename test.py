def indexnvalue(list) :
    val = list[0]
    index = 0
    for i in range(1,len(list)) :
        if(val < list[i]) :
            val = list[i]
            index = i
    return index,val

def solution(e, starts):
    a = min(starts)
    factors = [1] * (e+1)
    for i in range(2,e+1):
        f = (a // i) * i
        if f < a:
            f += i
        for j in range(f,e+1,i):
            factors[j] +=1 
    
    
    minis = [0] * (e-a+1)
    minis[e-a] = e
    
    #for j in range(e-1,a-1,-1) :
    #    if factors[j] >= factors[minis[j+1-a]] :
    #        minis[j-a] = j
    #    else :
    #        minis[j-a] = minis[j+1-a]
    
    indexed = list(enumerate(starts))
    indexed.sort(key=lambda x: x[1])
    indexed.reverse()
    myanswer = [0]
    prev = e
    for index,val in indexed:
        maxindex, maxval = indexnvalue(factors[val:prev+1])
        if maxval >= factors[myanswer[-1]] :
            myanswer.append(maxindex+val)
        else :
            myanswer.append(myanswer[-1])
        prev = val
    myanswer = myanswer[1:]
    #print(myanswer)
    answer = [0] * len(starts)
    for i in range(len(myanswer)) :
        index,val = indexed[i]
        answer[index] = myanswer[i]
    return answer
    