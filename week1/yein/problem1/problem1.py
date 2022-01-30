#https://www.acmicpc.net/problem/9935
#9935번-문자열 폭발

s = input()
bomb = input()
stack = []
for i in range(len(s)):
    stack.append(s[i])
    if len(stack)>=len(bomb):
        if ''.join(stack[-len(bomb):]) == bomb:
            for _ in range(len(bomb)): stack.pop()
if not stack: print("FRULA")
else: print(''.join(stack))
