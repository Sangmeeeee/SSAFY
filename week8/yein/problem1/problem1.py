# https://www.acmicpc.net/problem/2230
# 2230번-수 고르기
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
arr = sorted([int(input()) for _ in range(n)])

start, end = 0, 0
ans = sys.maxsize
while start < n and end < n:
    minus = arr[end]-arr[start]
    if minus == m:
        print(m)
        break
    if minus < m:
        end += 1
        continue
    start += 1
    ans = min(ans, minus)
else:
    print(ans)
