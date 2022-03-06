# https://www.acmicpc.net/problem/2437
# 2437번-저울

n = int(input())
arr = sorted(map(int, input().split()))
sum = 0
for i in range(n):
    if sum+1 < arr[i]:
        print(sum+1)
        break
    sum += arr[i]
else:
    print(sum+1)
