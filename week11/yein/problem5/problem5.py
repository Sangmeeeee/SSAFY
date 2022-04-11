#https://www.acmicpc.net/problem/1507
#1507번-궁금한 민호

n = int(input())
city = [list(map(int,input().split())) for _ in range(n)]
c = [[1]*n for _ in range(n)]
ans = 0

for k in range(n):
    for a in range(n):
        for b in range(n):
            if a==b or a==k or b==k: continue
            if city[a][b]==city[a][k]+city[k][b]: c[a][b]=0
            elif city[a][b]>city[a][k]+city[k][b]: ans =-1

if ans!=-1:
    for i in range(n):
        for j in range(i,n):
            if c[i][j]==1: ans += city[i][j]
print(ans)