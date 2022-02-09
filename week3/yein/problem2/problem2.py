#https://www.acmicpc.net/problem/13975
#13975번-파일 합치기 3
import heapq
for _ in range(int(input())):
    k = int(input())
    disk = list(map(int,input().split()))
    heapq.heapify(disk)
    ans = 0

    while len(disk)>1:
        sum = heapq.heappop(disk) + heapq.heappop(disk)
        ans+=sum
        heapq.heappush(disk,sum)
    print(ans)