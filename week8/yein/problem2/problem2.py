# https://www.acmicpc.net/problem/2470
# 2470번-두 용액

import sys
input = sys.stdin.readline
n = int(input())
arr = sorted(map(int, input().split()))

ans = [sys.maxsize,0,0]
start, end = 0, n-1
while start < end:
    mix = arr[start]+arr[end]
    if mix == 0:
        print(arr[start], arr[end])
        break
    if ans[0]>abs(mix):
        ans[0] = abs(mix)
        ans[1] = arr[start]
        ans[2] = arr[end]
        
    if mix > 0:end -= 1
    else:start += 1
else: print(ans[1], ans[2])
