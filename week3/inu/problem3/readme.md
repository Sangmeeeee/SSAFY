# Info

  

문제 : [메뉴 리뉴얼](https://programmers.co.kr/learn/courses/30/lessons/72411)

알고리즘 종류 : map, 정렬

참조 url :

  

# 알고리즘 설명
각 조합의 빈도수를 구하기 위해 key, value를 쌍으로 저장하는 map을 사용한다.   
map은 key를 기준으로 오름차순 정렬이 되는데 딱히 필요없어서 unordered_map을 사용했다.  
 
```c++
int cnt[i]                 // 길이가 i인 메뉴의 최대 등장 횟수  
vector<string> maxFreq[11] // 길이가 i이고 최대 등장 횟수를 가진 문자열
```
1. orders 내 문자열 자체를 오름차순으로 정렬해준다.
- 알파벳순으로 정렬이 안된 문자열이 포함되어 있을 수 있기 때문
2. 원래 문자열에서 조합 가능한 길이가 2 이상인 substring을 구해서 map에 넣는다.
-  이미 map에 있는 문자열이면 value값만 증가시킴
3. 현재 substring의 등장 횟수와 cnt[i]를 비교한다.
- 두 값이 같으면 maxFreq[i]에 substring을 넣는다.
- substring의 등장 횟수가 더 크면 maxFreq[i]를 비우고 substring을 넣는다.
4. cnt[i]에서 i가 course에 있고 cnt[i] >= 2이면 maxFreq[i]에 있는 모든 문자열을 answer 벡터에 넣는다.
5. answer에 있는 문자열들을 오름차순으로 정렬한다.

# 새로 배운 내용
map[key] 형식으로 value에 접근할 수 있다.  
map에 없는 key로 map[key]를 하면 알아서 추가된다.
