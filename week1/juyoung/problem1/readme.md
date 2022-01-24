# Info

문제 : [문자열 폭발](https://www.acmicpc.net/problem/9935)

알고리즘 종류 : 문자열

참조 url :

# 1. 알고리즘 설명

**string을 stack 형태로 구현**하여 문제를 풀었다.
1. answer라는 string 변수에 입력받은 문자열을 한 글자씩 끝에 push한다.
2. answer의 마지막 글자와 폭발 문자열의 마지막 글자가 같고, 현재 answer의 길이가 폭발 문자열 길이보다 같거나 길다면 answer와 폭발 문자열을 비교한다.
3. answer의 끝에서 폭발 문자열 길이만큼 자른 문자열이 폭발 문자열과 같다면 폭발 문자열의 길이만큼 answer를 pop한다.

# 2. 새로 배운 내용(코드 위주)

