#https://www.acmicpc.net/problem/3020
#3020번-개똥벌레 (누적 합을 잘 몰라서 접근하기 어려웠던 문제.. ㅜ)
n,h = map(int,input().split())
bottom = [0] * h
up = [0] * h
for i in range(0,n):
    k = int(input())
    if i % 2 == 0:bottom[k-1] += 1
    else:up[k-1] += 1

for i in range(h-1,0,-1):
    bottom[i-1] += bottom[i]
    up[i-1] += up[i]

cnt = 0
ans = 0
min = 200001
for i in range(h):
    cnt = bottom[i]+up[h-i-1]
    if min>cnt:
        min = cnt
        ans=1
    elif(min==cnt): ans+=1
print(min,ans)