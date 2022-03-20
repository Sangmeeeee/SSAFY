문제 : [다이어트](https://www.acmicpc.net/problem/1484)

알고리즘 종류 : 투포인터

참조 url : 

# 1. 알고리즘 설명

특정 구간을 명시해준게 아닌 자연수 두개의 차이가 G인 두 수를 찾는 문제이다.

특정 구간을 명시해주지 않았지만 G는 100,000보다 작거나 같다고 했기 때문에 두 수의 제곱의 차가 100,000보다 큰 시점에서 종료해준다.

어짜피 수는 계속해서 커져가고, 커져간 수의 제곱에서 빼는거기 때문에 차이는 100,000을 넘은 순간 100,000이하가 될 수 없다.

이 문제도 투포인터 문제이기 때문에 left를 당기고 right를 늘리는 방식으로 해결해준다. 그렇다면 종료할 경우는 right를 계속해서 늘렸을 때,

right의 제곱에 right - 1의 제곱을 뺀 값이 100,000을 넘을 경우 종료해준다.

처음은 left 1, right 1로 시작해준다. right는 성원이의 원래 몸무게이고 left는 성원이가 기억하는 몸무게이다.

right제곱 - left제곱을 했을 때의 결과가 G보다 작은경우 right를 늘려주고 G보다 큰 경우는 left를 당겨준다.

만약 G와 같을 경우는 right를 출력해주고 right를 늘려준다.

# 2. 새로 배운 내용

투 포인터문제를 많이 풀지는 않았지만 종료 조건에 많이 신경써야겠다고 느꼈다.