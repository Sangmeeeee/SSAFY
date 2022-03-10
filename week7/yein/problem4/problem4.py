# https://www.acmicpc.net/problem/5904
# 5904번-Moo 게임

N = int(input())


def moo(totalLen, middleLen, N):
    # 앞쪽 문자열의 길이
    prevLen = (totalLen-middleLen)//2
    # 앞쪽 문자열 조사
    if N <= prevLen:
        return moo(prevLen, middleLen-1, N)
    # 뒷쪽 문자열 조사
    elif N > prevLen+middleLen:
        return moo(prevLen, middleLen-1, N-prevLen-middleLen)
    # 중간 문자열이라면
    else:
        # 맨 앞의 문자가 아니면 o을 출력 맨 앞의 문자가 맞다면 m을 출력
        return "o" if N-prevLen-1 else "m"


length, k = 3, 0
# N번째의 문자가 있는 k를 구한다
while N > length:
    k += 1
    length = length*2+k+3

print(moo(length, k+3, N))
