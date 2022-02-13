#https://programmers.co.kr/learn/courses/30/lessons/72411
#프로그래머스-메뉴 리뉴얼
from itertools import combinations
from collections import defaultdict

def solution(orders, course):
    answer = []
    for c in course:
        menu = list(combinations(sorted(set(''.join(orders))),c))
        dict = defaultdict(list)
        for m in menu:
            cnt=0
            for i in range(len(orders)):
                check = False
                for a in m:
                    if a not in orders[i]:
                        check =False
                        break
                    else:
                        check = True
                if check:
                    cnt+=1
            if cnt >= 2:
                dict[cnt].append(''.join(m))
        if len(dict)!=0:
            for d in dict[max(dict)]:
                answer.append(d)
        else:
            break
                
    return sorted(answer)