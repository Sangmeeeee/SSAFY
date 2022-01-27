#https://www.acmicpc.net/problem/2212
#2212번-센서

n = int(input())
k = int(input())
sensor = sorted(map(int,input().split()))
interval = []

if k>=n: print(0)
else:
    for i in range(1,n):
        interval.append(sensor[i]-sensor[i-1])
    interval.sort()

    for _ in range(k-1):
        interval.pop()
    print(sum(interval))