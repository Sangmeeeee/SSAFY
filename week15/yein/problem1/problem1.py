#https://programmers.co.kr/learn/courses/30/lessons/60057
#프로그래머스-문자열 압축

def solution(s):
    answer = len(s)
    for i in range(1,len(s)//2+1):
        cnt = 1
        array = ''
        now = s[0:i]
        for j in range(i,len(s),i):
            if now == s[j:j+i]:
                cnt+=1
            else:
                if cnt>=2:
                    array+=str(cnt)+now
                else:
                    array+=now
                cnt=1
                now = s[j:j+i]
        if cnt>=2:
            array+= str(cnt)+now 
        else:
            array+=now
            
        answer= min(answer,len(array))
    return answer