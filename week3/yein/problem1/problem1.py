#https://www.acmicpc.net/problem/1715
#1715번-카드 정렬하기

import heapq
n = int(input())
cards = [int(input()) for _ in range(n)]
heapq.heapify(cards)
if len(cards)==1: print(0)
else:
    ans = 0
    while len(cards)>1:
        sum=heapq.heappop(cards) + heapq.heappop(cards)
        ans+=sum
        heapq.heappush(cards,sum)
    print(ans)