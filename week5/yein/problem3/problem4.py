#https://www.acmicpc.net/problem/16938
#16938번-캠프 준비

#combinations를 사용한 풀이
from itertools import combinations
N,L,R,X = map(int,input().split())
p = list(map(int,input().split()))
ans = 0
INF = int(1e9)
for i in range(2,N+1):
    for combi in combinations(p,i):
        sum = 0
        minValue,maxValue = INF,-INF
        for c in combi:
            sum+=c
            minValue = min(minValue,c)
            maxValue = max(maxValue,c)
        if L<=sum<=R and (maxValue - minValue)>=X:
            ans+=1
print(ans)

#재귀를 사용한 풀이
# N,L,R,X = map(int,input().split())
# p = list(map(int,input().split()))
# INF = int(1e9)
# ans = 0
# def backtracking(cnt,now,sum,minValue,maxValue):
#     global N,L,R,X,ans
#     if cnt>=2:
#         if L<=sum<=R and (maxValue-minValue)>=X: ans+=1
#     for i in range(now,N):
#         backtracking(cnt+1,i+1,sum+p[i],min(minValue,p[i]),max(maxValue,p[i]))

# backtracking(0,0,0,INF,-INF)
# print(ans)

# -----> combinations를 사용해서 풀이하는 것이 더 빨랐음.