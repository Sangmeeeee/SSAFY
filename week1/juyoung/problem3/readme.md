# Info

문제 : [괄호 제거](https://www.acmicpc.net/problem/2800)

알고리즘 종류 : 문자열, 스택, 재귀

참조 url :


# 1. 알고리즘 설명

**stack, vector, set container**와 **재귀 호출**을 통해 풀었다.

**stack**은 *괄호의 위치를 저장*하는 데, **vector**는 stack을 통해 서로 맞는 *괄호쌍의 위치를 pair 형태로 저장*하는 데, **set**은 *정답 문자열을 저장*하는 데 사용했다.

1. stack과 vector를 이용하여 괄호쌍 위치 파악
    a. 입력값을 첫번째 인덱스부터 탐색하며
        - ‘(’이면 stack에 해당 인덱스를 push한다.
        - ‘)’이면 vector에 {stack의 top, 해당 인덱스}를 저장하고 stack을 pop한다.
    b. 괄호쌍의 위치가 저장된 vector를 정렬한다.
 
2. 재귀적으로 호출하면서 괄호를 빼는 모든 경우를 set에 저장
    a. vector에 저장된 괄호쌍의 개수만큼 반복한다.
        - 방문 여부를 체크하고 true로 갱신한다.
        - false로 초기화된 check 배열에 괄호쌍의 위치를 true로 변경한다.
        - check 배열에서 true인 부분을 제외한 새로운 문자열을 생성하여 set에 삽입한다.
        - 재귀적으로 호출한 후, 방문 여부와 check 배열을 원상태(false)로 되돌린다.
 

# 2. 새로 배운 내용(코드 위주)

