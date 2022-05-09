문제 : [문자열 압축](https://programmers.co.kr/learn/courses/30/lessons/60057)

알고리즘 종류 : 문자열

참조 url :

# 1. 알고리즘 설명

일단 압축할 문자열의 길이를 wordlength라고 두었을 때, wordlength는 전체 문자열의 길이 절반까지만 비교해주면 된다.

이럴 전제로 두고 wordlength를 1부터 전체 문자열의 길이 n/2까지 늘려가며 문자열을 잘라준다.

기본 전략은 이렇다.

1. startIdx부터 startIdx + wordlength는 Base String이다(nextIdx부터 만들어지는 문자열과 비교해야함)
2. nextIdx의 시작은 항상 startIdx + wordlenght부터 시작한다.
3. nextIdx부터 nextIdx + wordlength까지의 sub 문자열이 Base문자열과 일치하다면 startIdx를 nextIdx로 옮겨주고 count를 + 1로해준다. Base문자열과 sub 문자열이 일치하지 않을때까지 실행해준다.
4. 만약 count가 0이라면 만들어지는 문자열의 길이는 Base String 혼자이기 때문에 Base String의 길이를 더해준다.
5. 만약 count가 1이상이라면 만들어지는 문자열의 길이는 (count + 1)의 자리수 + Base String의 길이를 더해준다. 여기서 count+1을 해주는 이유는 만약 abcabc와 같은 문자열이 압축됬을 경우 count는 1이지만 실제로는 2abc이기 때문이다.
6. 이를 startIdx + wordlength가 문자열의 길이보다 작거나 같을때 까지 해준다. 만약 startIdx가 10이고 wordlength는 3, 문자열의 길이는 12라면 마지막 2칸이 남게된다.
7. 이는 문제 조건에 따라 그냥 더해주면 되기 때문에 문자열의 길이 % wordlength값을 더해준다.

# 2. 새로 배운 내용
