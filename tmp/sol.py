def solution(S) :
    S = S.replace("plus","+")
    S = S.replace("minus","-")
    return S

print(solution("minusplusminus"))
print(solution("plusminusminusplus"))