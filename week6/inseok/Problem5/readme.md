문제 : [](https://www.acmicpc.net/problem/14891)[[저울]](https://www.acmicpc.net/problem/2437)

알고리즘 종류 : 그리디

참조 url :

# 1. 알고리즘 설명(로직위주)

## 문제 이해

확실히 그리디 문제는 뭔가 모르겠는 문제인데 풀리고 났을때 확실히 쉬운 로직? 으로 풀어내기에 내 자신이 대견하게 느껴지는듯.. 원래 그렇게 푸는거다.

## 로직

추를 sort 해준후  while 문을 돌면서 sum 을 구해준다. Sum[n] +1 < A 일때 Sum[n] 까지 만들수 있는 숫자이기에 Sum[n]+1 을 출력해준다.

# 2. 새로 배운 내용(코드위주)