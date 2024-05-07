def next_permutation(s):
    # 리스트 뒤에서부터 탐색하여 오름차순이 되는 지점 찾기
    n = len(s)
    i = n - 2
    while i >= 0 and s[i] >= s[i + 1]:
        i -= 1
    if i == -1:  # 다음 순열이 없을 때
        return False
    # s[i]보다 작은 다음 요소 찾기
    j = n - 1
    while s[i] >= s[j]:
        j -= 1
    s[i], s[j] = s[j], s[i]

    # i 이후 요소를 뒤집기
    s[i + 1:] = reversed(s[i + 1:])
    return True


T = int(input())
results = []

for t in range(1, T + 1):
    s = list(input())
    if next_permutation(s):
        results.append(''.join(s))
    else:
        results.append(''.join(s))

print("\n".join(results))
