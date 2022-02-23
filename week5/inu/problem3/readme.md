# Info

  

문제 : [캠프 준비](https://www.acmicpc.net/problem/16938)

알고리즘 종류 : 백트래킹

참조 url :

  

# 알고리즘 설명
N개의 문제 중에서 2개 이상 고르고 이 문제들이 문제의 조건에 맞는지 검사한다.  
조건에 맞는 조합이 몇개인지 찾아야하기 때문에 부분집합으로 모든 조합을 찾는다.
- 어떤 문제가 선택됐을 때, 선택되지 않았을 때를 나누어서 조합을 찾는다.
- 선택됐을 때는 selected[i] = true로, 선택되지 않았을 때는 selcted[i] = false로 표시한다.
- 선택된 문제가 2개 이상이 되면 그 문제들의 난이도 합, 최소값과 최대값 차이를 검사해서 조건에 맞으면 카운트를 1 증가시킨다.
# 새로 배운 내용