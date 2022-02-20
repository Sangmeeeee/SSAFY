#https://www.acmicpc.net/problem/1477
#1477번-휴게소 세우기
import heapq
import sys
input = sys.stdin.readline
n,m,l = map(int,input().split())
arr = [0]+sorted(map(int,input().split()))+[l]
d = []
for i in range(n+1): heapq.heappush(d,(-(arr[i+1]-arr[i]),1))
while m>0:
    a,div = heapq.heappop(d)
    og = abs(a*div)
    half =og/(div+1)
    heapq.heappush(d,(-half,div+1))
    m-=1
ans = abs(heapq.heappop(d)[0])
t = int(ans)
print(t+1 if ans!=t else t)