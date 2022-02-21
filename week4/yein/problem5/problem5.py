#https://programmers.co.kr/learn/courses/30/lessons/43163
#프로그래머스-단어 변환

answer = 50
visited = list()

def dfs(begin,target,words,cnt):
    global answer
    
    if begin == target:
        answer = min(answer,cnt)
        return 
    
    for i in range(len(words)):
        dif = 0
        if words[i] not in visited:
            for a,b in list(zip(begin,words[i])):
                if a!=b:
                    dif +=1
                if dif > 1 :
                    break
            if dif == 1: 
                visited.append(words[i])
                dfs(words[i],target,words,cnt+1)
                visited.pop()

def solution(begin, target, words):
    global answer 
    
    if target in words:
        dfs(begin,target,words,0)
    else:
        answer = 0
    
    return answer