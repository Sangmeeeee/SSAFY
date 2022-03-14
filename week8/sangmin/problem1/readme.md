문제 : [수 고르기](https://www.acmicpc.net/problem/2230)

알고리즘 종류 : 투포인터

참조 url : 

# 1. 알고리즘 설명

들어오는 수들의 차이를 구하기 위해 배열을 정렬해서 사용한다.

ary[right] - ary[left]를 했을 때 만약 그 값이 M보다 크다면 right와 left의 범위가 너무 넓은것이니 left를 당겨준다.

right를 늘리면 당연히 값이 커지면서 그 차이가 더 벌려지기 때문이다.

이 때, 정답은 M보다 큰 차이 중 가장 작은 값이기 때문에 Math.min으로 가장 작은 값을 찾아준다.

반대로 ary[right] - ary[left]를 했을 때 그 값이 M보다 작다면 범위가 너무 좁은것이기 때문에 right를 늘려준다.

ary[right] - ary[left] == M일경우 나올 수 있는 가장 작은 값 이기 때문에 종료해준다.

이렇게 right를 밀고 left를 당기는 작업을 right가 N보다 작을때동안 해준다.

# 2. 새로 배운 내용