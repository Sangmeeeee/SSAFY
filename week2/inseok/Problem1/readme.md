문제 : [연산자 끼워넣기(3)] ([url](https://www.acmicpc.net/problem/15659))

알고리즘 종류 : 백트래킹

참조 url : 

# 1. 알고리즘 설명(로직위주)

## 문제 이해

숫자와 사칙연산기호 갯수를 받아 max, min을 출력하는 문제이다.

백트래킹으로 문제 풀어야겠다고 생각했음. 하... 다 풀고나서 나중에 보니깐 연산자 우선순위를 생각을 안하고 앞에서 부터 연산 무조건 하게 풀었더라고... 그러고 나니깐 45분, 다시 풀고나니 126분 동안 했더라..

스택을 써야 할거라 했는데 스택을 쓰면 idx 위치 를 사용을 못하는 상황이 와서 나는 ArrayList를 사용 했다.

백트래킹을 써도 될 사이즈인가를 생각했을때 N 이 11 밖에 되지 않아서 최악 11!/(3!*3!*3!*2!) 이라 할 때 대충 천만 도 안될거 같아서 백트래킹으로 했다. 

탈출조건이 너무 길었는데 여기 체크 하는데 시간이 너무 많이 걸렸다 분명히 더 좋은 방법이 있을것 같다..

## 로직

먼저 arr에 숫자를 넣고, pmmd에 사칙연산 기호 갯수를 입력 받았다.

List<Integer> pmmdList를 생성하여 기호의 순서대로 넣어줄 리스트를 만들었다(백트래킹 할때 이것을 바꿔줄 예정)

### BTFunction(List<Integer>pmmdList, int startIdx)

탈출조건(basis part)

연산자 우선순위를 생각하여 *,/ 를 먼저 돌려준후 +- 를 돌려주어야한다. temp에 결과 값을 저장 해서 maxNum,minNum과 비교해 수정 해준다.

처음에 numList에 첫째숫자를 넣어준 상태에서 전체를 돌며 *,- 연산자를 만난경우 numList의 제일 위의 값을 꺼내 이를 계산한 값을 numList에 다시 저장해준다. 이렇게 되면 곱셈,나눗셈이 해결된 numList,pmmdList가 남게 된다.

여기서 pmmdList를 돌면서 곱셈 나눗셈은 해결했으니 넘겨주고, +- 가 나올경우에는 numList에서 값을 꺼내 더해 준다.

 

들어가는 조건(inductive part?)

pmmd가 양수이면 pmmd[i]를 하나 줄여주고 pmmdList.add(i) 를 해준후 BTFFunction(pmmdList,startIdx+1)을 다시 불러줬다. 이후 탈출했을때를 생각하여 바로뒤에 pmmd[i] 와 pmmdList를 정상화 해준다.

# 2. 새로 배운 내용(코드위주)