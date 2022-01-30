#https://programmers.co.kr/learn/courses/30/lessons/76502
#프로그래머스-괄호 회전하기

def solution(s):
    answer = 0
    dic = {')':'(',']':'[','}':'{'}
    cnt = 0
    while cnt<len(s):
        stack = []
        check = True
        for i in range(len(s)):
            if s[i] in ('(','[','{') : stack.append(s[i])
            elif stack and dic[s[i]]==stack[-1]: stack.pop()
            elif not stack:
                check = False
                break
        if check and not stack: answer+=1
        cnt+=1
        s= s[1:]+s[0]
    return answer
