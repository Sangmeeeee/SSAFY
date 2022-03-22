# Info

  

문제 : [LCS](https://www.acmicpc.net/problem/9251)

알고리즘 종류 : DP

참조 url : [링크](https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence)

  

# 알고리즘 설명
ACAYKP, CAPCAK에서 LCS를 구하기 전에 두 문자열의 부분 문자열에서 LCS를 구해보자 
- AC, CAPC에서 LCS는 AC이다. 이 두 문자열에 A를 추가해서 다시 비교해보자.
- ACA, CAPCA에서 LCS는 ACA이다. 이것은 AC, CAPC의 LCS에서 A를 더한 것이다. 
- 즉, 현재 비교하는 두 문자열의 LCS를 구할 때 미리 비교해놓은 값을 참고하기 때문에 DP로 해결할 수 있다.

<br>
비교하는 문자열의 LCS의 길이를 저장하는 배열을 LCS[i][j]라고 하자. 
 
string1의 1 ~ i번째까지의 substring과 string2의 1 ~ j번째까지의 substring의 LCS 길이를 의미한다.
- LCS[i][j]는 string1[i], string2[j]를 비교해서 결정된다.
	- string1[i] == string2[j]이면 LCS[i][j] = LCS[i - 1][j - 1] + 1  
	->  ACA, CAPCA의 LCS는 AC, CAPC의 LCS에 A를 붙인 것과 같다.
	- string1[i] != string2[j]이면 LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1])  
	-> ACAY, CAPCAK의 LCS는 ACA, CAPCAK의 LCS와 ACAY, CAPCA의 LCS 중 길이가 더 긴 것과 같다.


# 새로 배운 내용
### LCS : Longest Common Subsequence, 최장 공통 부분수열
- 같은 약자를 가지지만 다른 뜻을 가진 Longest Common Substring (최장 공통 부분 문자열)도 있다.
- 두 문자열 ABCEFG, KBCTEG이 있다고 할 때, 다음과 같은 차이가 있다.
	- Longest Common Substring: BC
	- Longest Common Subsequence: BCEG
