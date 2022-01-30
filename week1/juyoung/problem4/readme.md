# Info

문제 : [센서](https://www.acmicpc.net/problem/2212)

알고리즘 종류 : 정렬, 그리디 알고리즘

참조 url :


# 1. 알고리즘 설명

1. **인접한 센서 간의 거리**를 구하고, 이를 벡터에 저장한 후 오름차순으로 정렬한다.
2. 정렬한 벡터 제일 뒤의 (집중국의 수-1)개만큼을 빼고 전부 더한 것이 정답이다.

### 예제 입력 2
![2122(1)](https://user-images.githubusercontent.com/57346428/151377021-3869a28b-cac0-424c-a47b-2fe68bcbfaca.jpg)

집중국이 2개라면, 정렬한 벡터 제일 뒤에서 (집중국의 수-1)인 1개만큼을 빼고 전부 더한 14가 정답이다.

집중국이 3개라면, 정렬한 벡터 제일 뒤에서 (집중국의 수-1)인 3개만큼을 빼고 전부 더한 11이 정답이다.

### 또 다른 예시
![2122(2)](https://user-images.githubusercontent.com/57346428/151377025-9a460325-bf9c-4198-900f-b25ad3f7dcaf.jpg)

이 경우에는 정렬한 벡터 제일 뒤에서 (집중국의 수-1)인 1개만큼을 빼고 전부 더한 6이 정답이다.


# 2. 새로 배운 내용(코드 위주)

참조 url : https://mjmjmj98.tistory.com/38


### next_permutation()으로 순열 구하기

- `next_permutation` 사용 시 주의할 점
    1. 오름차순으로 정렬된 값을 가진 컨테이너로만 사용 가능하다.
    2. default로 operator <를 사용해 순열을 생성한다. 즉, 오름차순으로 순열을 생성한다.
    3. 중복이 있는 원소들은 중복을 제외하고 순열을 만든다.
  
- `next_permutation` 사용법
    ```cpp
    // {1, 2, 3}의 모든 순열 출력하기
    vector<int> v{ 1,2,3 };
    	
    	sort(v.begin(), v.end());
    	
    	do {
    		for (auto iter = v.begin(); iter != v.end(); iter++)
    			cout << *iter << " ";
    		cout << "\n";
    	} while (next_permutation(v.begin(), v.end()));
      
      /* 실행 결과
      1 2 3
      1 3 2
      2 1 3
      2 3 1
      3 1 2
      3 2 1
    ```
    
### prev_permutation()으로 조합 구하기
1. 크기가 n인 배열 `temp`를 만들어 r개의 원소는 1로, (n-r)개의 원소는 0으로 초기화한다.
2.  `temp`의 모든 순열을 구한다.
3.  `temp`의 순열에서 원소값이 1인 인덱스만 배열 s에서 가져온다.
 -  `temp`에서 **1이 있는 자리의 원소는 포함하고 0이 있는 자리의 원소는 미포함**한다.
   
    ```cpp
    // {1, 2, 3, 4} 중 2개의 원소를 고르는 모든 경우의 수 출력하기
    vector<int> s{ 1, 2, 3, 4 };
    vector<int> temp{ 1, 1, 0, 0 };
    
    do {
    	for (int i = 0; i < s.size(); i++) {
    		if (temp[i] == 1)
    			cout << s[i] << " ";
    	}
    	cout << "\n";
    } while (prev_permutation(temp.begin(), temp.end()));
    
    /* 실행 결과
    1 2
    1 3
    1 4
    2 3
    2 4
    3 4
    */
    ```
    
  - `prev_permutation`을 쓰는 이유
       - `next_permutation`을 사용하면 오름차순 정렬된다. 그럼 { 1, 1, 0, 0 }부터가 아니라 { 0, 0, 1, 1 }부터 실행하게 된다. 따라서 조합은 내림차순으로 출력된다.
        - `prev_permutation`은 내림차순 정렬된 데이터를 받아서 이전 순열로 바꿔준다.
 
