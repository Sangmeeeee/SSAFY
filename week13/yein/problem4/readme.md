# Info

문제 : [여행 가자](https://www.acmicpc.net/problem/1976)

알고리즘 종류 : 플로이드 워샬, 서로소 집합(union-find)

참조 url : 없음

# 알고리즘 설명
1. 도시의 수와 여행 계획에 속한 도시들의 수를 입력받는다.
2. i와 j가 같지 않다면 graph[i][j]==0일 때 int(1e9) 값으로 초기화시켜준다.
3. 3중 for문으로 플로이드 워샬 알고리즘을 진행해준다.
4. graph[travel[i]-1][travel[i+1]-1]==0이라면 check 변수를 False로 변경하고 break를 해준다.
5. check가 True라면 YES를 print 하고 그렇지 않다면 NO를 print 한다. 

# 새로 배운 내용
