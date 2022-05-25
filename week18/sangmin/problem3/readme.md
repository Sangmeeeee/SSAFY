문제 : [k진수에서 소수 개수 구하기](https://programmers.co.kr/learn/courses/30/lessons/92335)

알고리즘 종류 : 

참조 url : 

# 1. 알고리즘 설명

일단 10진수 n을 k진수로 변경하기 위해 StringBuilder에 더해가며 k진수로 변경해준다. 그 후 정규표현식 "[1-9]+"을 사용하여 P를 찾아준다.

P가 소수인지 아닌지 판단하기 위해 isPrime 함수를 사용하는데, Math.sqrt()를 사용해여 제곱근 까지만 판단해준다.

# 2. 새로 배운 내용

