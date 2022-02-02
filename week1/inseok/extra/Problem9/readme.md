문제 : [선 긋기] ([url](https://www.acmicpc.net/problem/2170))

알고리즘 종류 : 정렬

참조 url : 

# 1. 알고리즘 설명(로직위주)

## 문제 이해

문제 이해는 어려움 없었음.  20분만에 문제 다 푼건 처음인듯..

계속 정렬에 관련된 문제를 풀다보니 저절로  다중조건 정렬을 해야겠다는 생각을 했다.

이번에는 N이 최악의 경우 1,000,000 이라 시간복잡도, 공간복잡도를 조금 생각하면서 풀려고 노력했다. 

처음에 ArrayList를 잡아서 그려야 하는 list 를 수정하며 add 하려고 했는데 최악의경우 100만개의 list 가 그려질테고 이를 담을 공간 복잡도는 100만칸의 arrayList 가 되어 너무 크다 생각되어 방향을 수정해야겠다 생각했다.

시간복잡도는 sort 를 하는만큼이라 java 에 구현된 TimSort를 이용할 예정이기에 최악 O(NlogN)이라 생각 되었다.  (내가 구현 한 부분은 O(N))

## 로직

처음에 class Pair 를 만들어주어 start, end를 담을 수있는 클래스를 만들어주었다. 이를 Comparable 로 상속 하여 sort 했을때 start오름차순, 이후  end 오름차순으로 정렬되게 만들었다.

모든 페어를 입력받고 정렬 이후 int startTime, endTime, 그리고 int length를 두었다. 

페어들을 돌면서 startTime 이 Pair의 두 수 사이에 있다면 연장을 해야 하기에 기존의 endTime 과 pair의 end 중 큰녀석을 endTime 으로 수정해 주었다. 

만약 두 수 사이에 startTime 이 없다면 새로운 시작을 해야 하기에  length를 endTime- startTime 해주고, startTime, endTIme을 현재 Pair의 start 과 end 를 각각 수정해준다. 

그리고 for문을 다 순회 했을 때 마지막 startTime,endTime 만큼의  length 가 최신화 되지 않았기에 그만큼 더해주어야한다(테스트를 까다롭게 주었다면 못찾았을수도.. 테스트 돌려보면서 알았다.)