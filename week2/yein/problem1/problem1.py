#https://www.acmicpc.net/problem/15659
#15659번-연산자 끼워넣기 (3)
#덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수

N = int(input())
nums = list(map(int,input().split()))
calc = list(map(int,input().split()))
c = ['+','-','*','//']
combi = []
INF = int(1e9)
ans_min = INF
ans_max = -INF

def calculation():
    s = str(nums[0])
    for i in range(N-1):
        s+=combi[i]+str(nums[i+1])
    return eval(s)

def backtracking(cnt):
    global ans_max, ans_min

    if cnt==N-1:
        result = calculation()
        ans_max = max(ans_max,result)
        ans_min = min(ans_min,result)
        return

    for i in range(4):
        if calc[i]>0:
            calc[i]-=1
            combi.append(c[i])
            backtracking(cnt+1)
            calc[i]+=1
            combi.pop()

backtracking(0)
print(ans_max,ans_min,sep='\n')