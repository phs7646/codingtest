


N = int(input())
v = list(map(int, input().split()))

left = 0
right = N - 1
answer = 2100000000
answer_left = 0
answer_right = 0

while left < right:
    sum_value = v[left] + v[right]
    if abs(sum_value) < abs(answer):
        answer = sum_value
        answer_left = left
        answer_right = right
    if sum_value == 0:
        break
    if sum_value > 0:
        right -= 1
    else:
        left += 1

print(v[answer_left], v[answer_right])


