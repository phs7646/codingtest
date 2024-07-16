def calcul(A, numA):
    if numA == 0:
        return 0
    if numA == 1:
        return 0

    ret = 0
    remain = A * numA - A
    while remain >= A:
        ret += A * remain
        remain -= A
    return ret

def main():
    T = int(input())

    for t in range(1, T + 1):
        N,A,B = map(int,input().split())

        # Exception handling
        if N < A:
            print(f'#{t} {-1}')
            continue
        if N <= B:
            print(f'#{t} 0')
            continue
        if N % B == 0:
            print(f'#{t} {calcul(B, N // B)}')
            continue
        if A == B:
            print(f'#{t} {-1}')
            continue

        # Logic
        numB = N // B
        remain = N % B  # Greater than 0 and less than A. Thus, at least one B needs to be borrowed
        if remain >= A:
            print(f'#{t} {calcul(B, N // B) + remain * (B * numB)}')
            continue
        diff = B - A  # Greater than 0
        k = (A - remain + diff - 1) // diff  # Ceiling of (A - remain) / diff: minimum B to be borrowed
        if k > numB:
            print(f'#{t} {-1}')
            continue

        # Now k * B + remain can be divided into k + 1 chunks
        left = k * B + remain - (k + 1) * A  # Divide the last chunk into k + 1 chunks of A, then add left to one chunk
        numB -= k
        # B numB times, A k times, A + left once
        last = A + left
        totB = B * numB
        totA = A * k
        answer = calcul(A, k) + calcul(B, numB) + totA * totB + last * totA + last * totB
        print(f'#{t} {answer}')

if __name__ == "__main__":
    main()
